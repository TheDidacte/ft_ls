/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:46:20 by skiessli          #+#    #+#             */
/*   Updated: 2018/11/08 13:45:20 by skiessli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*u_dst;
	unsigned char	*u_src;
	size_t			i;

	u_dst = (unsigned char*)dst;
	u_src = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		u_dst[i] = u_src[i];
		i++;
	}
	return (dst);
}
