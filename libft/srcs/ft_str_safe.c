/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_safe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:32:37 by cpoirier          #+#    #+#             */
/*   Updated: 2018/12/18 18:27:30 by skiessli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char		*ft_strnew_safe(int len)
{
	char	*res;

	if (!(res = ft_strnew(len)))
		exit(1);
	return (res);
}

char		*ft_strdup_safe(const char *s)
{
	char	*res;

	if (!(res = ft_strdup(s)))
		exit(1);
	return (res);
}

char		get_safe_digit(long long l)
{
	l = l % 10;
	if (l < 0)
		l += 10;
	return ((char)l);
}
