/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:02:25 by cpoirier          #+#    #+#             */
/*   Updated: 2019/01/12 19:37:00 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				b_tree_cmp(t_b_tree *t1, t_b_tree *t2)
{
	if (g_flags.sort == ALPHA)
		return (ft_strcmp(t2->name, t1->name));
	else if (g_flags.sort == SIZE)
		return ((int)(t1->stat->st_size - t2->stat->st_size));
	else if (g_flags.sort == TIME)
	{
		if (g_flags.time == MOD)
			return ((int)(t1->stat->st_mtimespec.tv_sec
						- t2->stat->st_mtimespec.tv_sec));
		else if (g_flags.time == ACCESS)
			return ((int)(t1->stat->st_atimespec.tv_sec
						- t2->stat->st_atimespec.tv_sec));
		else
			return ((int)(t1->stat->st_birthtimespec.tv_sec
						- t2->stat->st_birthtimespec.tv_sec));
	}
	return (0);
}

static int		get_type(struct stat *st)
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

t_b_tree		*init_b_tree(char *path)
{
	t_b_tree		*res;

	if (!(res = (t_b_tree *)malloc(sizeof(t_b_tree))))
		return (0);
	res->path = ft_strdup(s);
	res->name = ft_strrchr(res->path, '/') + 1;
	if (g_flags.sort == TIME || g_flags.sort == SIZE || g_flags.color
			|| g_flags.format = LONG)
	{
		if (!(res->stat = (t_stat *)malloc(sizeof(t_stat))))
			exit(1);
		lstat(s, res->stat);
		res->type = get_type(res->stat);
	}
	res->is_dir = 0;
	res->left = 0;
	res->right = 0;
	res->last = &(res->right);
	return (res);
}

void			insert_in_btree(t_b_tree **father, t_b_tree *child)
{
	if (!(*father))
		*father = child;
	else if (g_flags.not_sorted)
	{
		*((*father)->last) = child;
		(*father)->last = child->last;
	}
	else
	{
		if ((g_flags.reverse && b_tree_cmp(*father, child) < 0)
				|| (!g_flags.reverse && b_tree_cmp(*father, child) > 0))
			insert_in_btree(&((*father)->left));
		else
			insert_in_btree(&((*father)->right));
	}
}
