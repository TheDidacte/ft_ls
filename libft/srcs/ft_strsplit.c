/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:14:04 by skiessli          #+#    #+#             */
/*   Updated: 2018/11/08 13:37:14 by skiessli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

static int	count_words(char const *s, char c)
{
	int		count;

	count = 1;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static int	get_word_length(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s && *s != c)
	{
		count++;
		s++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;

	if (!s || !(ret = (char **)malloc(count_words(s, c) * sizeof(char*))))
		return (NULL);
	i = 0;
	ret[count_words(s, c) - 1] = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			return (ret);
		ret[i] = ft_strnew(get_word_length(s, c));
		ft_strncpy(ret[i], s, get_word_length(s, c));
		ret[i][get_word_length(s, c)] = 0;
		i++;
		s += get_word_length(s, c);
	}
	return (ret);
}
