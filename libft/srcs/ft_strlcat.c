/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:01:07 by skiessli          #+#    #+#             */
/*   Updated: 2018/11/08 13:43:52 by skiessli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

size_t		ft_strlcat(char *dst, char *src, size_t n)
{
	size_t	i;
	size_t	total;

	total = ft_min(ft_strlen(dst), n) + ft_strlen(src);
	i = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (*dst && i < n)
	{
		dst++;
		i++;
	}
	if (i == n)
		return (n + ft_strlen(src));
	while (*src && i < n - 1)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = 0;
	return (total);
}
