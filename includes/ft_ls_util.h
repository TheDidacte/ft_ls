/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:04:24 by skiessli          #+#    #+#             */
/*   Updated: 2019/01/12 17:43:55 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_UTIL_H
# define FT_LS_UTIL_H

#include <unistd.h>

typedef struct 	s_linfo
{
	blkcnt_t	b_c;
	size_t		total;
	size_t		max_links;
	size_t		max_usr;
	size_t		max_grp;
	size_t		max_size;
}				t_linfo;
	

char	*read_flags(int *ac, char ***argv);

void	print_tree_lst(t_tree *t, t_tree_list *p);
void	print_tree_std(t_tree *t, t_tree_list *p);
void	print_tree_stream(t_tree *t, t_tree_list *p);
void	print_tree_long(t_tree *t, t_tree_list *p);

size_t	get_max_len(t_tree_list *p);
void	collect_info(t_linfo *info, t_tree_list *p);

int		is_empty(t_tree *tree);

t_tree	*init_tree(const char *s);
void	add_child(t_tree *father, t_tree *son);

size_t	get_intmax(int a, size_t b);
int		get_type(struct stat *st);


void	loop_and_print_start(int ac, char **av);
int			is_arg_valid(char *path);
void		print_tree_aux(t_tree *tree);
#endif
