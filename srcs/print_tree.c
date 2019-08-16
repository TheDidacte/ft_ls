/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:07:10 by cpoirier          #+#    #+#             */
/*   Updated: 2019/01/12 18:38:18 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_ls_util.h"
#include "../libft/includes/libft.h"

static void	(*ptr[])(t_tree *, t_tree_list *) = {print_tree_std,
		print_tree_long, print_tree_stream, print_tree_lst};

int			is_doted(char *s)
{
	int		i;

	i = ft_strlen(s);
	if (!i)
		return (1);
	i--;
	if (s[i] == '.')
	{
		if (i == 0 || s[i - 1] == '/')
			return (1);
		if ((i == 1 && s[i - 1] == '.') || (s[i - 1] == '.' && s[i - 2] == '/'))
			return (1);
	}
	return (0);
}

void		print_tree_aux(t_tree *tree)
{
	static int		first_dir = 1;
	t_tree_list		*p;

	if (!tree)
		return ;
	if (tree->is_dir && (!is_doted(tree->path) || first_dir))
	{
		if ((g_flags.recursive && !first_dir) || g_flags.multiple_args)
		{
			if (!first_dir || g_flags.has_lonely)
				ft_printf_m("\n");
			else
				first_dir = 0;
			ft_printf_m("%s:\n", tree->path);
		}
		else
			first_dir = 0;
		ptr[g_flags.format](tree, tree->children);
		/*
		p = tree->children;
		while (p)
		{
			if (tree->is_dir  && g_flags.recursive)
				print_tree_aux(p->tree);
			p = p->next;
		}
		*/
	}
}

void		print_tree(t_tree *tree)
{
	t_tree_list		*p;

	handle_lonely_files(tree);
	p = tree->children;
	while (p)
	{
		print_tree_aux(p->tree);
		p = p->next;
	}

}
