/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:26:50 by skiessli          #+#    #+#             */
/*   Updated: 2018/12/14 11:26:52 by skiessli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/flags.h"
#include "../includes/printf_util.h"
#include "../includes/libft.h"
#include "../includes/str_safe.h"
#include <stdlib.h>

char		*non_print_fix(char *str)
{
	char			*ret;
	int				i;
	int				j;
	static char		*hex = "0123456789abcdef";

	if (!(ret = ft_strnew(ft_strlen(str) * 4)))
		exit(1);
	i = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] >= 32 && str[j] <= 126)
			ret[i] = str[j];
		else
		{
			ret[i++] = '\\';
			ret[i++] = 'x';
			ret[i++] = hex[((unsigned char)str[j]) / 16];
			ret[i] = hex[((unsigned char)str[j]) % 16];
		}
		i++;
		j++;
	}
	free(str);
	return (ret);
}

void		write_non_print_string(t_flags *fl, int *c, va_list ap)
{
	int		len;
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	str = ft_strdup_safe(str);
	str = non_print_fix(str);
	len = ft_strlen(str);
	if (fl->precision && fl->precision_num < len)
	{
		str[fl->precision_num] = 0;
		len = fl->precision_num;
	}
	str = add_width(0, fl, str, &len);
	write_to_buff(str, len);
	(*c) += len;
	free(str);
}
