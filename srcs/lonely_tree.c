/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonely_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:55:27 by cpoirier          #+#    #+#             */
/*   Updated: 2019/01/11 18:56:37 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_ls_util.h"

static void (*ptr[])(t_tree *, t_tree_list *) = {print_tree_std,
	        print_tree_long, print_tree_stream, print_tree_lst};

void			print_tree_simple(t_tree *t)
{
	t_tree_list *p;

	p = t->children;
	while (p)
	{
		//printf("Tree: %s\n", p->tree->path);
		p = p->next;
	}
}

void			print_lonely_files(t_tree *res)
{
	ptr[g_flags.format](res, res->children);
	g_flags.has_lonely = 1;
}

void			handle_lonely_files(t_tree *tree)
{
	t_tree		*res;
	t_tree_list	*p;

	p = tree->children;
	res = init_tree("lonely files");
	while (p)
	{
		if (!p->tree->is_dir)
			add_child(res, init_tree(p->tree->path));
		p = p->next;
	}
	if (res->children)
		print_lonely_files(res);
	//free_tree(res);
	g_flags.lonely = 0;
}
