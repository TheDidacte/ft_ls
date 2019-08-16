/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:04:08 by skiessli          #+#    #+#             */
/*   Updated: 2018/11/06 17:10:11 by skiessli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;
	char			*ret;

	if (!s)
		return (NULL);
	start = 0;
	while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t') &&
		s[start] != 0)
		start++;
	if (s[start] == 0)
		return (ft_strnew(0));
	end = ft_strlen(s) - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	ret = ft_strnew(end - start + 1);
	if (!ret)
		return (NULL);
	ft_strncpy(ret, &(s[start]), end - start + 1);
	ret[end - start + 2] = 0;
	return (ret);
}
