/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:32:02 by skiessli          #+#    #+#             */
/*   Updated: 2018/11/06 13:36:58 by skiessli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*ret;
	size_t	i;

	ret = malloc(size);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ret[i] = 0;
		i++;
	}
	return ((void*)ret);
}
