/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:00:42 by skiessli          #+#    #+#             */
/*   Updated: 2018/11/06 16:24:43 by skiessli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*itoa_helper(char *ret, long num, unsigned len)
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

char		*ft_itoa(int n)
{
	unsigned int	len;
	long			num;
	char			*ret;

	len = 0;
	num = (long)n;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	if (num <= 0)
	{
		len++;
		num *= -1;
	}
	if (!(ret = ft_strnew(len)))
		return (NULL);
	return (itoa_helper(ret, num, len));
}
