/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_util.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:56:45 by cpoirier          #+#    #+#             */
/*   Updated: 2018/12/13 16:04:17 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_UTIL_H
# define PRINTF_UTIL_H

# include <string.h>
# include "flags.h"

void		populate_flags(const char **fmt, t_flags *fl, va_list ap);
char		*get_int_str(const char **fmt, t_flags *fl, va_list ap);
char		*add_alternate(const char **fmt, t_flags *fl, char *str, int *len);
char		*add_width(int is_shit, t_flags *fl, char *str, int *len);
char		*add_prefix(const char **fmt, t_flags *fl, char *str, int *len);
char		*add_zeros(t_flags *fl, char *str, int *len);
void		write_to_buff(const char *str, size_t len);
void		convert(const char **fmt, int *c, va_list ap);
char		*get_double_str(long double d, t_flags *l);
void		convert(const char **fmt, int *c, va_list ap);

#endif
