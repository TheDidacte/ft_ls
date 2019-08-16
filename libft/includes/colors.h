/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:51:45 by cpoirier          #+#    #+#             */
/*   Updated: 2019/01/06 15:30:58 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "libft.h"
# include "stdlib.h"
# include <unistd.h>

# define COLORS 11

# define RED		"\x1B[31m"
# define GRN		"\x1B[32m"
# define YEL		"\x1B[33m"
# define BLU		"\x1B[34m"
# define MAG		"\x1B[35m"
# define CYN		"\x1B[36m"
# define WHT		"\x1B[37m"
# define RST		"\x1B[0m"
# define BLD		"\x1B[01m"
# define UDL		"\x1B[04m"
# define HLG		"\x1B[07m"

void		write_colors(int fd, char *str, size_t len);

#endif
