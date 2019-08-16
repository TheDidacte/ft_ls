/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:53:57 by skiessli          #+#    #+#             */
/*   Updated: 2018/11/06 15:05:14 by skiessli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	if (!s || !f)
		return (NULL);
	ret = ft_strnew(ft_strlen(s));
	i = 0;
	if (!ret)
		return (NULL);
	while (s[i])
	{
		ret[i] = (*f)(s[i]);
		i++;
	}
	return (ret);
}
