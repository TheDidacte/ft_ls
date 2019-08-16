/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:26:16 by cpoirier          #+#    #+#             */
/*   Updated: 2018/12/14 10:36:41 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/str_safe.h"
#include "../includes/printf_util.h"
#include "../includes/libft.h"
#include <stdlib.h>

void		write_float(t_flags *fl, int *c, va_list ap)
{
	char	*str;
	int		len;

	fl->precision_num = fl->precision ? fl->precision_num : 6;
	if (fl->length[0] == 'L')
		str = get_double_str(va_arg(ap, long double), fl);
	else
		str = get_double_str(va_arg(ap, double), fl);
	len = ft_strlen(str);
	str = add_width(1, fl, str, &len);
	(*c) += len;
	write_to_buff(str, len);
	free(str);
}

void		write_char(t_flags *fl, int *c, va_list ap)
{
	char	chr;
	int		len;
	char	*str;

	chr = va_arg(ap, int);
	str = ft_strdup_safe(&chr);
	len = 1;
	str = add_width(0, fl, str, &len);
	write_to_buff(str, len);
	free(str);
	(*c) += len;
}

void		write_string(t_flags *fl, int *c, va_list ap)
{
	int		len;
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	str = ft_strdup_safe(str);
	len = ft_strlen(str);
	if (fl->precision && fl->precision_num < len)
	{
		str[fl->precision_num] = 0;
		len = fl->precision_num;
	}
	str = add_width(0, fl, str, &len);
	write_to_buff(str, len);
	(*c) += len;
	free(str);
}

void		write_percentage(t_flags *fl, int *c)
{
	char	*str;
	int		len;

	str = ft_strdup_safe("%");
	len = 1;
	str = add_width(0, fl, str, &len);
	write_to_buff(str, len);
	free(str);
	(*c) += len;
}

void		write_not_found(const char **fmt, t_flags *fl, int *c)
{
	char	*str;
	int		len;

	str = ft_strdup_safe(*fmt);
	len = 1;
	str = add_width(0, fl, str, &len);
	write_to_buff(str, len);
	free(str);
	(*c) += len;
}
