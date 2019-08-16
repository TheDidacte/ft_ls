/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:31:36 by cpoirier          #+#    #+#             */
/*   Updated: 2019/01/11 20:35:22 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "../libft/includes/libft.h"

int				get_list_size(t_tree_list *p)
{
	if (p)
		return (1 + get_list_size(p->next));
	return (0);
}

int				tree_cmp(t_tree *t1, t_tree *t2)
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

void			sort_tree_list(t_tree_list **p)
{
	int			i;
	int			j;
	t_tree_list	**t;
	t_tree_list	*tmp;

	i = get_list_size(*p) - 1;
	while (i)
	{
		j = 0;
		t = p;
		while (j++ < i)
		{
			if ((!g_flags.reverse && tree_cmp((*t)->tree, (*t)->next->tree) < 0)
					|| (g_flags.reverse && tree_cmp((*t)->tree
							, (*t)->next->tree) > 0))
			{
				tmp = (*t)->next;
				(*t)->next = tmp->next;
				tmp->next = (*t);
				*t = tmp;
			}
			t = &((*t)->next);
		}
		i--;
	}
	tmp = (*p);
	while (tmp)
	{
		if (tmp->tree->children)
			sort_tree_list(&(tmp->tree->children));
		tmp = tmp->next;
	}
}

void			sort_tree(t_tree *tree)
{
	sort_tree_list(&(tree->children));
}
