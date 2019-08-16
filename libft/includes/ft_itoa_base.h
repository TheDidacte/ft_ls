/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:05:29 by cpoirier          #+#    #+#             */
/*   Updated: 2018/12/13 16:17:51 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITOA_BASE_H
# define FT_ITOA_BASE_H

# include "flags.h"

char		*ft_itoa_long(long long n, t_flags *fl);
char		*ft_itoa_base(unsigned long long num, unsigned int base,
		const char **fmt, t_flags *fl);

#endif
