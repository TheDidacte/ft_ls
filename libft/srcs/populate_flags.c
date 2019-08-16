/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:53:08 by cpoirier          #+#    #+#             */
/*   Updated: 2018/12/13 16:05:00 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/flags.h"

int			ft_atoi_and_skip(const char **str)
{
	int		ret;

	ret = ft_atoi(*str);
	while (**str >= '0' && **str <= '9')
		(*str)++;
	return (ret);
}

void		pop_flags_end(const char **fmt, t_flags *fl, va_list ap)
{
	if (**fmt == 'h' || **fmt == 'l' || **fmt == 'L' || **fmt == 'j' ||
			**fmt == 'z')
	{
		if (!fl->length[0] || **fmt != 'h')
			fl->length[0] = **fmt;
		else
			fl->length[1] = **fmt;
	}
	(void)ap;
}

void		pop_flags_mid(const char **fmt, t_flags *fl, va_list ap)
{
	if (**fmt >= '1' && **fmt <= '9')
	{
		if ((fl->width_num = ft_atoi_and_skip(fmt)))
		{
			fl->width = 1;
			(*fmt)--;
		}
	}
	else if (**fmt == '.')
	{
		(*fmt)++;
		if (**fmt == '*')
		{
			fl->precision_num = va_arg(ap, int);
			fl->precision = (fl->precision_num >= 0) ? 1 : fl->precision;
		}
		else
		{
			fl->precision_num = ft_atoi_and_skip(fmt);
			fl->precision = 1;
			(*fmt)--;
		}
	}
	else
		pop_flags_end(fmt, fl, ap);
}

void		pop_flags_beg(const char **fmt, t_flags *fl, va_list ap)
{
	if (**fmt == '-')
		fl->minus = 1;
	else if (**fmt == '+')
		fl->plus = 1;
	else if (**fmt == ' ')
		fl->space = 1;
	else if (**fmt == '0')
		fl->zero = 1;
	else if (**fmt == '#')
		fl->hash = 1;
	else if (**fmt == '*')
	{
		fl->width = 1;
		fl->width_num = va_arg(ap, int);
		if (fl->width_num < 0)
		{
			fl->width_num *= -1;
			fl->minus = 1;
		}
	}
	else
		pop_flags_mid(fmt, fl, ap);
}

void		populate_flags(const char **fmt, t_flags *fl, va_list ap)
{
	while (**fmt == '-' || **fmt == '+' || **fmt == ' ' || **fmt == '0' || **fmt
			== '#' || **fmt == '.' || **fmt == '*' || (**fmt >= '1' && **fmt <=
				'9') || **fmt == 'h' || **fmt == 'l' || **fmt == 'L' || **fmt
			== 'j' || **fmt == 'z')
	{
		pop_flags_beg(fmt, fl, ap);
		(*fmt)++;
	}
}
