/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:53:12 by cpoirier          #+#    #+#             */
/*   Updated: 2019/01/12 18:14:27 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "../libft/includes/libft.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>

void			set_back_color(char c)
{
	char		*s;
	char		*s2;

	if (c == 'x')
		return ;
	s = "\x1B[";
	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	s2 = ft_itoa(c - 'a' + 40);
	s = ft_strjoin(s, s2);
	free(s2);
	s2 = s;
	s = ft_strjoin(s, "m");
	free(s2);
	ft_printf_m(s);
	free(s);
}

void			set_text_color(char c)
{
	char		*s;
	char		*s2;

	if (c == 'x')
		return ;
	s = "\x1B[";
	if (c >= 'A' && c <= 'Z')
	{
		ft_printf_m("\x1B[01m");
		c += 'a' - 'A';
	}
	s2 = ft_itoa(c - 'a' + 30);
	s = ft_strjoin(s, s2);
	free(s2);
	s2 = s;
	s = ft_strjoin(s, "m");
	free(s2);
	ft_printf_m(s);
	free(s);
}

void			print_name(t_tree *tree, int width)
{
	static char	*colors = 0;
	char		*name;
	
	if (!colors)
		colors = getenv("LSCOLORS");
	if (g_flags.color && tree->type < 42)
	{
		set_back_color(colors[tree->type * 2 + 1]);
		set_text_color(colors[tree->type * 2]);
		name = g_flags.lonely ? tree->path : tree->name;
		ft_printf_m("%s%s", name, "\x1B[00m");
		if (isatty(STDOUT_FILENO) && width)
			ft_printf_m("%b", width - ft_strlen(name));
		else if (width)
		{
			while (width - (int)ft_strlen(name) > 0)
			{
				ft_printf_m("\t");
				width -= 8;
			}
		}
			
	}
	else
	{
		name = g_flags.lonely ? tree->path : tree->name;
		ft_printf_m("%s", name);
		if (isatty(STDOUT_FILENO) && width)
			ft_printf_m("%b", width - ft_strlen(name));
		else if (width)
		{
			while (width - (int)ft_strlen(name) > 0)
			{
				//ft_printf("%i", width);
				ft_printf_m("\t");
				width -= 8;
			}
		}
	}
	if (g_flags.lonely)
		free(name);
}
