/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:50:25 by skiessli          #+#    #+#             */
/*   Updated: 2018/11/06 13:50:28 by skiessli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/libft.h"

static void	help_putnbr(int n, int fd)
{
	int	s;

	if (n == 0)
		return ;
	s = n % 10;
	if (s < 0)
		s *= -1;
	help_putnbr(n / 10, fd);
	ft_putchar_fd('0' + s, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
		write(fd, "-", 1);
	help_putnbr(n, fd);
}
