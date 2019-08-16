/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:01:33 by skiessli          #+#    #+#             */
/*   Updated: 2018/11/07 16:18:01 by skiessli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t		j;
	size_t		i;

	i = 0;
	if (*needle == 0)
		return ((char*)haystack);
	while (haystack[i])
	{
		while (haystack[i] && haystack[i] != *needle)
			i++;
		if (!haystack[i])
			return (NULL);
		j = 1;
		while (haystack[i + j] == needle[j] && needle[j] != 0)
			j++;
		if (needle[j] == 0)
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
