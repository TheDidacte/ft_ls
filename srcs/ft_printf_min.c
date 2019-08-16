/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:40:41 by cpoirier          #+#    #+#             */
/*   Updated: 2019/01/12 14:59:24 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include "ft_ls.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

void		write_spaces(int n)
{
	static char	*s = " ";

	while (n-- > 0)
		wtob(s);
}

void		handle_conv(char *s, va_list ap)
{
	char		*conv;
	static int	cut = 0;

	if (s[1] == 'c')
	{
		g_buf->buf[g_buf->cursor] = (char)va_arg(ap, int);
		g_buf->cursor++;
	}
	else if (s[1] == 's')
	{
		if (!cut)
			wtob(va_arg(ap, char *));
		else
		{
			wntob(va_arg(ap, char *), cut);
			cut = 0;
		}
	}
	else if (s[1] == 'i')
	{
		conv = ft_itoa(va_arg(ap, int));
		wtob(conv);
		free(conv);
	}
	else if (s[1] == 'b')
		write_spaces(va_arg(ap, int));
	else if (s[1] == 'C')
		cut = va_arg(ap, int);
}

void		ft_printf_m(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)format;
	va_start(ap, format);
	while (str[i])
	{
		if (str[i] == '%')
		{
			wntob(str, i);
			str += i;
			handle_conv(str, ap);
			str += 2;
			i = 0;
		}
		else
			i++;
	}
	wtob(str);
	va_end(ap);
}
