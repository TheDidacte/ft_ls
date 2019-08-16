/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:57:47 by skiessli          #+#    #+#             */
/*   Updated: 2018/11/07 17:36:19 by skiessli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*u_dst;
	unsigned char	*u_src;

	i = 0;
	u_src = (unsigned char *)src;
	u_dst = (unsigned char *)dst;
	while (i < n && ((unsigned char)c) != u_src[i])
	{
		u_dst[i] = u_src[i];
		i++;
	}
	if (i < n)
	{
		u_dst[i] = u_src[i];
		return ((void*)&u_dst[i + 1]);
	}
	return (NULL);
}
