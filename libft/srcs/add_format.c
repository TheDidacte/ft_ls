/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:04:15 by cpoirier          #+#    #+#             */
/*   Updated: 2018/12/13 15:33:40 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/flags.h"
#include "../includes/str_safe.h"
#include <stdlib.h>

char		*add_alternate(const char **fmt, t_flags *fl, char *str, int *len)
{
	char	*ret;
	int		shift;

	ret = str;
	while (*ret && *ret == '0')
		ret++;
	if ((fl->hash && *ret != 0 && (**fmt == 'X' || **fmt == 'x' || ((**fmt ==
						'o' || **fmt == 'O') && *str != '0'))) || **fmt == 'p')
	{
		shift = (**fmt == 'o' || **fmt == 'O') ? 1 : 2;
		*len += shift;
		ret = ft_strnew_safe(*len);
		ft_strcpy(ret + shift, str);
		ret[0] = '0';
		if (shift == 2)
			ret[1] = (**fmt == 'X') ? 'X' : 'x';
		free(str);
		str = ret;
	}
	return (str);
}

int			check_stupid_width(char *res, char *str, int *len, t_flags *fl)
{
	if ((ft_strstr(str, "0x") || ft_strstr(str, "0X")) && (fl->zero &&
				!fl->precision))
	{
		res[0] = str[0];
		res[1] = str[1];
		ft_memset(res + 2, '0', fl->width_num - *len);
		ft_strcpy(res + fl->width_num - *len + 2, str + 2);
	}
	else if ((*str == '-' || *str == '+' || *str == ' ') && (fl->zero &&
				!fl->precision))
	{
		res[0] = str[0];
		ft_memset(res + 1, '0', fl->width_num - *len);
		ft_strcpy(res + fl->width_num - *len + 1, str + 1);
	}
	else
		return (0);
	return (1);
}

char		*add_width(int is_shit, t_flags *fl, char *str, int *len)
{
	char	*ret;

	if (!fl->width || fl->width_num <= *len)
		return (str);
	ret = ft_strnew_safe(fl->width_num);
	if (fl->minus)
	{
		ft_strcpy(ret, str);
		ft_memset(ret + *len, ' ', fl->width_num - *len);
	}
	else
	{
		if (!is_shit || !check_stupid_width(ret, str, len, fl))
		{
			ft_strcpy(ret + fl->width_num - *len, str);
			if (fl->zero && (!fl->precision || !is_shit))
				ft_memset(ret, '0', fl->width_num - *len);
			else
				ft_memset(ret, ' ', fl->width_num - *len);
		}
	}
	*len = fl->width_num;
	free(str);
	return (ret);
}

char		*add_prefix(const char **fmt, t_flags *fl, char *str, int *len)
{
	char	*ret;

	if (!(fl->plus || fl->space) || (**fmt != 'i' && **fmt != 'd' && **fmt !=
				'D') || str[0] == '-')
		return (str);
	(*len)++;
	ret = ft_strnew_safe(*len);
	ft_strcpy(ret + 1, str);
	if (fl->space)
		ret[0] = ' ';
	if (fl->plus)
		ret[0] = '+';
	free(str);
	return (ret);
}

char		*add_zeros(t_flags *fl, char *str, int *len)
{
	char	*ret;
	int		shift;

	shift = (str[0] == '-') ? 1 : 0;
	if (!fl->precision || fl->precision_num <= *len - shift)
		return (str);
	ret = ft_strnew_safe(fl->precision_num + shift);
	ft_strcpy(ret + shift + fl->precision_num - (*len - shift), str + shift);
	ft_memset(ret + shift, '0', fl->precision_num - (*len - shift));
	if (shift)
		ret[0] = '-';
	*len = fl->precision_num + shift;
	free(str);
	return (ret);
}
