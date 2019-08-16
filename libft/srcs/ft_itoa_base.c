/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:02:29 by cpoirier          #+#    #+#             */
/*   Updated: 2018/12/18 18:25:53 by skiessli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/flags.h"
#include "../includes/str_safe.h"

static char	*itoa_helper(char *ret, unsigned long long num, unsigned len)
{
	ret[0] = '-';
	len--;
	if (num == 0)
		ret[0] = '0';
	while (num != 0)
	{
		ret[len] = '0' + (num % 10);
		num = num / 10;
		len--;
	}
	return (ret);
}

char		*ft_itoa_long(long long n, t_flags *fl)
{
	unsigned int			len;
	long long				tmp;
	unsigned long long		num;
	char					*ret;

	if (n == 0 && fl->precision && fl->precision_num == 0)
		return (ft_strdup_safe(""));
	len = 0;
	tmp = n;
	while (tmp != 0)
	{
		tmp = tmp / 10;
		len++;
	}
	if (n <= 0)
	{
		len++;
		num = n * -1;
	}
	else
		num = n;
	if (!(ret = ft_strnew(len)))
		return (NULL);
	return (itoa_helper(ret, num, len));
}

char		*ft_itoa_base(unsigned long long num, unsigned int base,
		const char **fmt, t_flags *fl)
{
	char				*range;
	unsigned int		len;
	unsigned long long	n;
	char				*ret;

	if (num == 0 && fl->precision && fl->precision_num == 0 &&
			!(fl->hash && (**fmt == 'o' || **fmt == 'O')))
		return (ft_strdup_safe(""));
	range = **fmt == 'X' ? "0123456789ABCDEFX" : "0123456789abcdefx";
	len = 1;
	n = num / base;
	while (n != 0)
	{
		n = n / base;
		len++;
	}
	ret = ft_strnew(len--);
	while (num >= base)
	{
		ret[len] = range[num % base];
		num /= base;
		len--;
	}
	ret[len] = range[num % base];
	return (ret);
}
