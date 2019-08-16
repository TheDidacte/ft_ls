/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:25:53 by skiessli          #+#    #+#             */
/*   Updated: 2019/01/12 14:46:22 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "../includes/colors.h"
#include "../includes/libft.h"
#include "../includes/str_safe.h"
#include "../includes/printf_util.h"

#define BUFFSIZE 1048576

int			g_fd;
char		*g_buf;

void		write_to_buff(const char *str, size_t len)
{
	static int	written = 0;

	if (written + len >= BUFFSIZE || len == 0)
	{
		/*write_colors(g_fd, g_buf, written);*/
		ft_bzero(g_buf, written);
		written = 0;
		if (len >= BUFFSIZE)
			write(g_fd, str, len);
		else
		{
			ft_memcpy(g_buf, str, len);
			written = len;
		}
	}
	else
	{
		ft_memcpy(g_buf + written, str, len);
		written += len;
	}
}

int			ft_vdprintf(int fd, const char *format, va_list ap)
{
	int		c;

	c = 0;
	g_fd = fd;
	g_buf = ft_strnew_safe(BUFFSIZE);
	while (*format)
	{
		if (*format != '%')
		{
			write_to_buff(format, 1);
			c++;
			format++;
		}
		else
			convert(&format, &c, ap);
	}
	//write_to_buff("", 0);
	free(g_buf);
	return (c);
}

int			ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		c;

	va_start(ap, format);
	c = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (c);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		c;

	va_start(ap, format);
	c = ft_vprintf(format, ap);
	va_end(ap);
	return (c);
}
