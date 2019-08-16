/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 12:38:10 by skiessli          #+#    #+#             */
/*   Updated: 2019/01/12 19:35:11 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <stdarg.h>

# define STD	0
# define LONG	1
# define STREAM	2
# define LIST	3

# define ALPHA	0
# define SIZE	1
# define TIME	2

# define MOD	0
# define ACCESS	1
# define CREATE 2


typedef struct stat t_stat;
typedef struct dirent t_dirent;
typedef struct passwd t_passwd;
typedef struct group t_group;

typedef struct			s_flags
{
	unsigned int		recursive : 1;
	unsigned int		not_sorted : 1;
	unsigned int		color : 1;
	unsigned int		human : 1;
	unsigned int		numerical : 1;
	unsigned int		slash : 1;
	unsigned int		sort : 2;
	unsigned int		time : 2;
	unsigned int		reverse : 1;
	unsigned int		format : 3;
	unsigned int		all : 1;
	unsigned int		all_A : 1;
	unsigned int		complete_time : 1;
	unsigned int		extended : 1;
	unsigned int		omit_group : 1;
	unsigned int		multiple_args : 1;
	unsigned int		lonely : 1;
	unsigned int		has_lonely : 1;
}						t_flags;

typedef struct s_tree_list t_tree_list;

typedef struct			s_tree
{	
	char				*path;
	char				*name;
	t_stat				*stat;
	t_dirent			*dirent;
	t_tree_list			*children;
	int					is_dir : 1;
	int					type;
}						t_tree;

typedef struct			s_tree_list
{
	t_tree				*tree;
	struct s_tree_list	*next;
}						t_tree_list;

typedef struct			s_buffer
{
	char				*buf;
	size_t				size;
	size_t				cursor;
}						t_buffer;

typedef struct			s_b_tree
{
	struct s_b_tree		*left;
	struct s_b_tree		*right;
	struct s_b_tree		**last;
	char				*path;
	char				*name;
	t_stat				*stat;
	int					is_dir : 1;
	int					type;
}						t_b_tree;

t_tree					*create_tree(int ac, char **av);
void					print_tree(t_tree *tree);
void					sort_tree(t_tree *tree);
void					print_name(t_tree *tree, int width);
void					handle_lonely_files(t_tree *tree);
int						tree_cmp(t_tree *t1, t_tree *t2);

t_buffer				*get_buffer(size_t n);
void					wtob(char *s);
void					wntob(char *s, size_t n);
void					ft_printf_m(const char *format, ...);

extern	t_flags		g_flags;
extern	t_buffer	*g_buf;

#endif
