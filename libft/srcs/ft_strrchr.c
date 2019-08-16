/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:01:21 by skiessli          #+#    #+#             */
/*   Updated: 2019/01/11 18:36:30 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*start;

	start = (char*)s;
	while (*s != 0)
		s++;
	while (*s != (char)c && s != start)
		s--;
	if (*s == (char)c)
		return ((char*)s);
	return (start- 1);
}
