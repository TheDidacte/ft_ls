/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:39:10 by cpoirier          #+#    #+#             */
/*   Updated: 2018/12/14 10:41:42 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/write_types.h"
#include "../includes/libft.h"
#include "../includes/flags.h"
#include "../includes/printf_util.h"

void		output_with_flags(const char **fmt, t_flags *fl, int *c, va_list ap)
{
	if (!**fmt)
		return ;
	else if (**fmt == '%')
		write_percentage(fl, c);
	else if (**fmt == 'd' || **fmt == 'i' || **fmt == 'u' || **fmt == 'o'
			|| **fmt == 'x' || **fmt == 'X' || **fmt == 'p' || **fmt == 'D'
			|| **fmt == 'O' || **fmt == 'U' || **fmt == 'b')
		write_int(fmt, fl, c, ap);
	else if (**fmt == 'f' || **fmt == 'F')
		write_float(fl, c, ap);
	else if (**fmt == 'c' || **fmt == 'C')
		write_char(fl, c, ap);
	else if (**fmt == 's' || **fmt == 'S')
		write_string(fl, c, ap);
	else if (**fmt == 'r')
		write_non_print_string(fl, c, ap);
	else
		write_not_found(fmt, fl, c);
	(*fmt)++;
}

void		convert(const char **fmt, int *c, va_list ap)
{
	t_flags		fl;

	ft_bzero(&fl, sizeof(t_flags));
	(*fmt)++;
	populate_flags(fmt, &fl, ap);
	output_with_flags(fmt, &fl, c, ap);
}
