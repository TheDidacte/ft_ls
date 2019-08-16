/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:00:29 by skiessli          #+#    #+#             */
/*   Updated: 2018/11/07 17:58:32 by skiessli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

char	*ft_strdup(const char *s1)
{
	char	*ret;

	if (!(ret = ft_strnew(ft_strlen(s1))))
		return (NULL);
	return (ft_strcpy(ret, s1));
}
