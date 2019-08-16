/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:36:32 by skiessli          #+#    #+#             */
/*   Updated: 2019/01/12 15:05:04 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>

void	print_flag_error(char *prog_name, char *argv)
{
	ft_dprintf(2, "%s: illegal option -- %1s\n", prog_name, argv);
	ft_dprintf(2, "usage: %s: [-ACGRSTUafhloprtu1@] [file ...]\n", prog_name);
	exit(1);
}

void	read_flag(char *argv, char *prog_name)
{
	while (*argv)
	{
		if (*argv == 'l')
			g_flags.format = LONG;
		else if (*argv == 'R')
			g_flags.recursive = 1;
		else if (*argv == 'a')
			g_flags.all = 1;
		else if (*argv == 'r')
			g_flags.reverse = 1;
		else if (*argv == 't')
			g_flags.sort = TIME;
		else if (*argv == '@')
			g_flags.extended = 1;
		else if (*argv == 'A')
			g_flags.all_A = 1;
		else if (*argv == 'C')
			g_flags.format = STD;
		else if (*argv == 'f')
		{
			g_flags.not_sorted = 1;
			g_flags.all = 1;
		}
		else if (*argv == 'G')
			g_flags.color = 1;
		else if (*argv == 'h')
			g_flags.human = 1;
		else if (*argv == 'm')
			g_flags.format = STREAM;
		else if (*argv == 'n')
		{
			g_flags.numerical = 1;	
			g_flags.format = LONG;
		}
		else if (*argv == 'p')
			g_flags.slash = 1;
		else if (*argv == 'o')
		{
			g_flags.omit_group = 1;
			g_flags.format = LONG;
		}
		else if (*argv == 'S')
			g_flags.sort = SIZE;
		else if (*argv == 'T')
			g_flags.complete_time = 1;
		else if (*argv == 'u')
			g_flags.time = ACCESS;
		else if (*argv == 'U')
			g_flags.time = CREATE;
		else if (*argv == '1')
			g_flags.format = LIST;
		else
			print_flag_error(prog_name, argv);	
		argv++;
	}	
}

char	*read_flags(int *ac, char ***argv)
{
	char	*prog_name;

	prog_name = **argv;
	(*argv)++;
	(*ac)--;
	if (!isatty(STDOUT_FILENO))
		g_flags.format = LIST;
	while (*ac > 0)
	{
		if (***argv != '-')
		   break;
		read_flag((**argv) + 1, prog_name);
		(*argv)++;
		(*ac)--;
	}
	g_flags.multiple_args = *ac > 1 ? 1 : 0;
	g_flags.lonely = 1;
	return (prog_name);
}
