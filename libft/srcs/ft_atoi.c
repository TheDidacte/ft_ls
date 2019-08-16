/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:28:36 by skiessli          #+#    #+#             */
/*   Updated: 2019/01/06 15:30:15 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	long	ret;
	int		neg;

	neg = 1;
	ret = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		str++;
		neg = -1;
	}
	else if (*str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		if (ret > (ret * 10 + *str - '0') && neg == 1)
			return (-1);
		if (ret > (ret * 10 + *str - '0') && neg == -1)
			return (0);
		ret = ret * 10 + *str - '0';
		str++;
	}
	return (neg * ret);
}
