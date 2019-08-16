/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 19:41:41 by skiessli          #+#    #+#             */
/*   Updated: 2019/01/12 18:19:19 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../includes/ft_ls_util.h"
#include "../libft/includes/libft.h"

t_flags		g_flags; 
t_buffer	*g_buf;

int		main(int ac, char **argv)
{
	t_tree	*tree;

	g_buf = get_buffer(2097152);
	bzero(&g_flags, sizeof(t_flags));
	read_flags(&ac, &argv);
	loop_and_print_start(ac, argv);
	//tree = create_tree(ac, argv);
	//write(1,"test\n",5);
	//if (!is_empty(tree))
	//	print_tree(tree);
	write_and_free();
	//write_to_buff("", 0);
	//free_tree(tree);
	return (0);
}
