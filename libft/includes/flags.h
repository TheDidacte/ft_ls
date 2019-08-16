/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:07:04 by cpoirier          #+#    #+#             */
/*   Updated: 2018/12/13 15:43:42 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include <stdarg.h>

typedef	struct	s_flags
{
	int			hash;
	int			minus;
	int			plus;
	int			zero;
	int			space;
	int			width;
	int			width_num;
	int			precision;
	int			precision_num;
	char		length[2];
}				t_flags;

#endif
