/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_cnv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:06:18 by cpoirier          #+#    #+#             */
/*   Updated: 2018/12/14 10:37:59 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/flags.h"
#include "../includes/str_safe.h"

size_t		get_double_length(long double d, t_flags *l)
{
	long double		power;
	size_t			res;

	if (d < 0)
	{
		res = 3;
		d = -d;
	}
	else
		res = 2;
	power = 10.0;
	while (d >= power)
	{
		power *= 10.0;
		res++;
	}
	res += l->precision_num;
	if (l->precision_num)
		res++;
	return (res);
}

int			get_double_power(long double d)
{
	long double		power;
	int				res;

	power = 10.0;
	res = 1;
	while (d >= power)
	{
		power *= 10.0;
		res++;
	}
	return (res);
}

void		round_double(long double *d, int precision)
{
	int		i;
	int		is_neg;

	is_neg = *d < 0 ? 1 : 0;
	i = 0;
	*d = *d < 0 ? -*d : *d;
	while (i++ < precision)
		*d *= 10.0;
	if (((long long)(*d * 10)) % 10 > 4)
		*d += 1.0;
	while (--i)
		*d /= 10.0;
	*d = is_neg ? -*d : *d;
}

char		*add_double_digits(char *res, long double d, int m_p, t_flags *l)
{
	size_t		i;
	size_t		j;

	if (!l->precision_num)
		return (res);
	i = ((d < 0) ? 1 : 0) + m_p + 1;
	res[i - 1] = '.';
	j = 0;
	if (d < 0)
		d = -d;
	d *= 10.0;
	while ((int)j < l->precision_num)
	{
		res[i + j] = get_safe_digit((long long)d % 10) + '0';
		d *= 10.0;
		j++;
	}
	return (res);
}

char		*get_double_str(long double d, t_flags *l)
{
	size_t			len;
	char			*res;
	size_t			i;
	int				max_power;
	long double		d_cpy;

	round_double(&d, l->precision_num);
	len = get_double_length(d, l);
	d_cpy = d;
	if (!(res = (char *)malloc(len)))
		exit(1);
	res[len - 1] = '\0';
	i = 0;
	res[0] = (d < 0) ? '-' : '.';
	d = (d < 0) ? -d : d;
	max_power = get_double_power(d);
	while ((int)i < max_power)
	{
		res[max_power - i + ((*res == '-') ? 0 : -1)] =
			get_safe_digit((long long)d % 10) + '0';
		i++;
		d /= 10.0;
	}
	return (add_double_digits(res, d_cpy, max_power, l));
}
