/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:52:13 by cpoirier          #+#    #+#             */
/*   Updated: 2018/12/14 12:26:00 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colors.h"
#include "../includes/str_safe.h"

char	*g_colors[COLORS] = {
	RED,
	GRN,
	YEL,
	BLU,
	MAG,
	CYN,
	WHT,
	RST,
	BLD,
	UDL,
	HLG
};

char	*g_c_hint[COLORS] = {
	"{red}",
	"{grn}",
	"{yel}",
	"{blu}",
	"{mag}",
	"{cyn}",
	"{wht}",
	"{rst}",
	"{bld}",
	"{udl}",
	"{hlg}"
};

void		write_colors(int fd, char *str, size_t len)
{
	char		*res;
	size_t		i;
	int			color_index;

	res = ft_strnew_safe(len);
	i = 0;
	while (i < len)
	{
		color_index = 0;
		while (color_index < COLORS && ft_strstr(str + i, g_c_hint[color_index])
				- str - i)
			color_index++;
		if (color_index < COLORS)
		{
			ft_strncpy(res + i, g_colors[color_index], 5);
			i += 5;
		}
		else
		{
			res[i] = str[i];
			i++;
		}
	}
	write(fd, res, len);
	free(res);
}
