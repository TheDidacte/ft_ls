/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:06:51 by cpoirier          #+#    #+#             */
/*   Updated: 2019/01/12 16:07:39 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>

t_buffer	*get_buffer(size_t size)
{
	t_buffer		*res;

	if (!(res = (t_buffer *)malloc(sizeof(t_buffer))))
		exit(1);
	if (!(res->buf = (char *)malloc(size)))
		exit(1);
	res->size = size;
	res->cursor = 0;
	return (res);
}

void		print_and_reset(t_buffer *buf)
{
	write(1, buf->buf, buf->cursor);
	buf->cursor = 0;
}

void		realloc_buffer(t_buffer *buf)
{
	size_t		i;
	char		*tmp;

	i = 0;
	tmp = ft_strdup(buf->buf);
	free(buf->buf);
	if (!(buf->buf = (char *)malloc(buf->size * 4)))
		exit(1);
	while (i++ < buf->size)
		buf->buf[i - 1] = tmp[i - 1];
	free(tmp);
	buf->size = buf->size * 4;
}

void		wtob(char *s)
{
	size_t		len;

	len = ft_strlen(s);
	if (g_buf->cursor + len >= g_buf->size)
	{
		print_and_reset(g_buf);
		//realloc_buffer(g_buf);
	}
	ft_strcpy(g_buf->buf + g_buf->cursor, s);
	g_buf->cursor += len;
}

void		wntob(char *s, size_t n)
{
	if (g_buf->cursor + n >= g_buf->size)
		realloc_buffer(g_buf);
	ft_strncpy(g_buf->buf + g_buf->cursor, s, n);
	g_buf->cursor += n;
}

void		write_and_free(void)
{
	write(1, g_buf->buf, g_buf->cursor);
	free(g_buf->buf);
	free(g_buf);
}
