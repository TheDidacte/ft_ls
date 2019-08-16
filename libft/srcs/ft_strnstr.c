/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:01:41 by skiessli          #+#    #+#             */
/*   Updated: 2018/11/08 13:43:13 by skiessli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		j;
	size_t		i;

	i = 0;
	if (*needle == 0)
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i] && haystack[i] != *needle && i < len)
			i++;
		if (!haystack[i])
			return (NULL);
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] != 0 && i + j < len)
			j++;
		if (needle[j] == 0)
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
