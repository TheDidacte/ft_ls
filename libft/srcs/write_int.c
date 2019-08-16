/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:58:31 by cpoirier          #+#    #+#             */
/*   Updated: 2018/12/14 10:47:29 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/flags.h"
#include "../includes/ft_itoa_base.h"
#include "../includes/libft.h"
#include "../includes/printf_util.h"
#include <stdlib.h>

int			get_base(const char **fmt)
{
	if (**fmt == 'o' || **fmt == 'O')
		return (8);
	else if (**fmt == 'p' || **fmt == 'x' || **fmt == 'X')
		return (16);
	else if (**fmt == 'b')
		return (2);
	return (10);
}

char		*get_int_str_end(const char **fmt, t_flags *fl, va_list ap)
{
	if (fl->length[0] == 'j')
	{
		return (ft_itoa_base((uintmax_t)va_arg(ap, unsigned long long),
					get_base(fmt), fmt, fl));
	}
	if (fl->length[0] == 'z')
	{
		return (ft_itoa_base((size_t)va_arg(ap, unsigned long long),
					get_base(fmt), fmt, fl));
	}
	return (ft_itoa_base(va_arg(ap, unsigned int), get_base(fmt), fmt, fl));
}

char		*get_int_str_aux(const char **fmt, t_flags *fl, va_list ap)
{
	if (fl->length[0] == 'l' || **fmt == 'O' || **fmt == 'U' || **fmt == 'p')
	{
		if (fl->length[1] == 'l')
		{
			return (ft_itoa_base(va_arg(ap, unsigned long long), get_base(fmt),
						fmt, fl));
		}
		return (ft_itoa_base(va_arg(ap, unsigned long), get_base(fmt), fmt,
					fl));
	}
	if (fl->length[0] == 'h')
	{
		if (fl->length[1] == 'h')
		{
			return (ft_itoa_base((unsigned char)va_arg(ap, unsigned int),
						get_base(fmt), fmt, fl));
		}
		return (ft_itoa_base((unsigned short)va_arg(ap, unsigned int),
					get_base(fmt), fmt, fl));
	}
	return (get_int_str_end(fmt, fl, ap));
}

char		*get_int_str(const char **fmt, t_flags *fl, va_list ap)
{
	if (**fmt == 'i' || **fmt == 'd' || **fmt == 'D')
	{
		if (fl->length[0] == 'l' || **fmt == 'D')
		{
			if (fl->length[1] == 'l')
				return (ft_itoa_long(va_arg(ap, long long), fl));
			return (ft_itoa_long(va_arg(ap, long), fl));
		}
		if (fl->length[0] == 'h')
		{
			if (fl->length[1] == 'h')
				return (ft_itoa_long((char)va_arg(ap, int), fl));
			return (ft_itoa_long((short)va_arg(ap, int), fl));
		}
		if (fl->length[0] == 'j')
			return (ft_itoa_long((intmax_t)va_arg(ap, long long), fl));
		if (fl->length[0] == 'z')
			return (ft_itoa_long((ssize_t)va_arg(ap, long long), fl));
		return (ft_itoa_long(va_arg(ap, int), fl));
	}
	return (get_int_str_aux(fmt, fl, ap));
}

void		write_int(const char **fmt, t_flags *fl, int *c, va_list ap)
{
	char	*str;
	int		len;

	str = get_int_str(fmt, fl, ap);
	len = ft_strlen(str);
	str = add_zeros(fl, str, &len);
	str = add_prefix(fmt, fl, str, &len);
	str = add_alternate(fmt, fl, str, &len);
	str = add_width(1, fl, str, &len);
	(*c) += len;
	write_to_buff(str, len);
	free(str);
}
