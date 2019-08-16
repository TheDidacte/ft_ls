/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:25:12 by skiessli          #+#    #+#             */
/*   Updated: 2018/11/09 15:25:16 by skiessli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	ret;

	ret = 0;
	while (s[ret] && ret < maxlen)
		ret++;
	return (ret);
}
