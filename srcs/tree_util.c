/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 12:57:36 by cpoirier          #+#    #+#             */
/*   Updated: 2019/01/12 18:38:16 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "../libft/includes/libft.h"

#include <stdlib.h>

#include <sys/stat.h>

#include <sys/types.h>
#include <sys/dir.h>

#include <dirent.h>

#include <stdio.h>

#include <errno.h>

/*
void		print_tree(t_tree *tree)
{
	if (!tree)
		return ;
	printf("Name: %s\n", tree->path);
	//if (tree->stat)
	//	printf("Is dir ? %d\n\n", S_ISDIR(tree->stat->st_mode));
	if (tree->children)
	{
		t_tree_list *p = tree->children;
		

		while (p)
		{
			print_tree(p->tree);
			p = p->next;
		}

	}
}
*/

int			is_empty(t_tree *tree)
{
	if (!tree || !tree->children || !tree->children->tree)
		return (1);
	return (0);
}

int			is_arg_valid(char *path)
{
	struct stat		st;

	errno = 0;
	if (stat(path, &st) < 0 || (S_ISDIR(st.st_mode) && !opendir(path)))
	{
		ft_dprintf(2, "ft_ls: %s: %s\n", path, strerror(errno));
		return (0);
	}
	return (1);
}

int			get_type(struct stat *st)
{
	if (S_ISUID & st->st_mode)
		return (7);
	else if (S_ISGID & st->st_mode)
		return (8);
	else if (S_ISVTX & st->st_mode)
		return (9);
	else if (2 & st->st_mode && S_ISDIR(st->st_mode))
		return (10);
	else if (S_ISDIR(st->st_mode))
		return (0);
	else if (S_ISCHR(st->st_mode))
		return (6);
	else if (S_ISFIFO(st->st_mode))
		return (3);
	else if (S_ISLNK(st->st_mode))
		return (1);
	else if (S_ISSOCK(st->st_mode))
		return (2);
	else if (S_ISBLK(st->st_mode))
		return (5);
	else if (S_IXUSR & st->st_mode)
		return (4);
	else
		return (42);
}

t_tree		*init_tree(const char *s)
{
	t_tree		*res;
	DIR			*d;
	t_dirent	*dir;

	if (!(res = (t_tree *)malloc(sizeof(t_tree))))
		return (0);
	res->path = ft_strdup(s);
	res->name = ft_strrchr(res->path, '/') + 1;
	//if (!(res->stat = (t_stat *)malloc(sizeof(t_stat))))
	//	exit(1);
	//lstat(s, res->stat);
	//res->type = get_type(res->stat);
	res->children = 0;
	res->is_dir = 0;

	d = opendir(res->path);
	if (d)
	{
		res->is_dir = 1;
		closedir(d);
	}
	return (res);
}

void		sort_insert(t_tree_list **l, t_tree_list *el)
{
	while ((*l) && (g_flags.not_sorted
				|| ((!g_flags.reverse && tree_cmp((*l)->tree, el->tree) > 0)
			|| (g_flags.reverse && tree_cmp((*l)->tree, el->tree) < 0))))
		l = &((*l)->next);
	if (!(*l))
		*l = el;
	else
	{
		el->next = *l;
		*l = el;
	}
}

void		add_child(t_tree *father, t_tree *son)
{
	t_tree_list		*t_son;

	if (!father->children)
	{
		if (!(father->children = (t_tree_list *)malloc(sizeof(t_tree_list))))
			return ;
		father->children->tree = son;
		father->children->next = 0;
	}
	else
	{
		if (!(t_son = (t_tree_list *)malloc(sizeof(t_tree_list))))
			return ;
		t_son->tree = son;
		t_son->next = 0;
		sort_insert(&(father->children), t_son);
	}
}

char		*add_name(const char *s1, char *s2)
{
	char	*res;
	size_t	l1;

	l1 = ft_strlen(s1);
	if (!(res = (char *)malloc(l1 + ft_strlen(s2) + 2)))
		exit(1);
	ft_strcpy(res, s1);
	res[l1] = '/';
	ft_strcpy(res + l1 + 1, s2);
	return (res);
}

t_tree		*get_tree_from_dir(const char *path)
{
	t_tree		*res;
	DIR			*d;
	t_dirent	*dir;

	res = init_tree(path);
	res->is_dir = 1;
	d = opendir(path);
	if (d)
	{
		while ((dir = readdir(d)))
		{
			if (dir->d_type == DT_DIR && ft_strcmp(dir->d_name, ".")
					&& ft_strcmp(dir->d_name, "..") && g_flags.recursive
					&& (g_flags.all || g_flags.all_A || *dir->d_name != '.'))
			{
				char *s1 = add_name(path, dir->d_name);
				add_child(res, get_tree_from_dir(s1));
				free(s1);
			}
			else if (g_flags.all || *dir->d_name != '.' || (g_flags.all_A
						&& ft_strcmp(dir->d_name, ".")
						&& ft_strcmp(dir->d_name, "..")))
			{
				char *s1 = add_name(path, dir->d_name);
				add_child(res, init_tree(s1));
				free(s1);
			}
		}
		closedir(d);
	}
	return (res);
}

t_tree		*create_tree(int ac, char **av)
{
	t_tree		*res;
	int			i;

	i = -1;
	if (!(res = (t_tree *)malloc(sizeof(t_tree))))
		exit(1);
	res->path = "main";
	res->children = 0;
	if (ac == 0)
		add_child(res, get_tree_from_dir("."));
	while (++i < ac)
	{
		if (is_arg_valid(av[i]))
			add_child(res, get_tree_from_dir(av[i]));
	}
	return (res);
}
