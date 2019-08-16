/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree_simple.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:18:23 by skiessli          #+#    #+#             */
/*   Updated: 2019/01/12 15:05:32 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_ls_util.h"
#include "../libft/includes/libft.h"
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>

size_t    get_display_count(t_tree_list *p, size_t max)
{
    struct winsize  w;

    if (isatty(STDOUT_FILENO))
    {
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        return (w.ws_col / max);
    }
    else
        return (80 / max);
        //return (80 / ((((max - 1) / 8) + 1) * 8 ));
}

size_t    get_display_width(t_tree_list *p)
{
    struct winsize  w;

    if (isatty(STDOUT_FILENO))
    {
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        return (w.ws_col);
    }
    else
        return (80);
}

void	print_tree_lst(t_tree *t, t_tree_list *p)
{
	while (p)
	{
		print_name(p->tree, 0);//ft_printf_m("%s\n", p->tree->path);
		ft_printf_m("\n");
		p = p->next;
	}
}

size_t    init_names_array(t_tree_list *p, t_tree ***names, size_t *count)
{
    size_t      i;
    t_tree_list *lst;
    size_t      height;

    i = 0;
    lst = p;
    while (p)
    {
        p = p->next;
        i++;
    }
    height = 0;
    while (height * *count < i)
        height++;
    *count = ((i - 1 ) / height) + 1;
    if (!(*names = ft_memalloc(sizeof(t_tree **) * height * *count)))
        exit(1);
    i = 0;
    while (lst)
    {
        (*names)[*count*(i%height) + (i / height)] = lst->tree;
        lst = lst->next;
        i++;
    }
    return (height);
}

void	print_tree_std(t_tree *t, t_tree_list *p)
{
    size_t  		width;
    size_t			i;
    size_t			count;
    t_tree          **names;
    size_t          height;

    width = get_max_len(p) + 1;
    if (!isatty(STDOUT_FILENO))
        width = ((((width - 1) / 8) + 1) * 8 ); 
    count = get_display_count(p, width);
    if (count == 0 || !p)
    	return (print_tree_lst(t,p));
	height = init_names_array(p, &names, &count);
    i = 0;
    while (i < height * count)
    {
    	if ((i + 1) % count == 0 )
    	{
            if (names[i])
                print_name(names[i], 0);
    		ft_printf_m("\n");
		}
    	else
    		print_name(names[i], names[i + 1] ? width : 0);
        i++;
    }
    if (i % count != 0)
    {
    	ft_printf_m("\n");
	}
    free(names);
}

void	print_tree_stream(t_tree *t, t_tree_list *p)
{
    size_t      dis_width;
    size_t      c;

    dis_width = get_display_width(p);
    c = 0;
	if (p)
	{
		print_name(p->tree, 0);//ft_printf_m("%s", p->tree->path);
        c += strlen(ft_strrchr(p->tree->path, '/') + 1) + 2;
		p = p->next;	
	}
	while (p)
	{
		ft_printf_m(", ");
        if (c + strlen(ft_strrchr(p->tree->path, '/') + 1) + 2 >= dis_width)
        {
            ft_printf_m("\n");
            c = 0;
        }
        c += strlen(ft_strrchr(p->tree->path, '/') + 1) + 2;
		print_name(p->tree, 0);
		p = p->next;
	}
	ft_printf_m("\n");
}
