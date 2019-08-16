/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:59:57 by skiessli          #+#    #+#             */
/*   Updated: 2018/11/07 17:43:18 by skiessli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*u_dst;
	unsigned char	*u_src;
	size_t			i;

	u_dst = (unsigned char *)dst;
	u_src = (unsigned char *)src;
	if (len == 0)
		return (dst);
	i = -1;
	if (u_dst > u_src)
	{
		i = len - 1;
		while (i > 0)
		{
			u_dst[i] = u_src[i];
			i--;
		}
		u_dst[i] = u_src[i];
	}
	else
	{
		while (++i < len)
			u_dst[i] = u_src[i];
	}
	return (dst);
}
