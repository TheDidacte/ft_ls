/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:28:54 by cpoirier          #+#    #+#             */
/*   Updated: 2018/12/13 15:32:54 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_TYPES_H
# define WRITE_TYPES_H

# include "flags.h"

void		write_float(t_flags *fl, int *c, va_list ap);
void		write_char(t_flags *fl, int *c, va_list ap);
void		write_string(t_flags *fl, int *c, va_list ap);
void		write_percentage(t_flags *fl, int *c);
void		write_not_found(const char **fmt, t_flags *fl, int *c);
void		write_int(const char **fmt, t_flags *fl, int *c, va_list ap);
void		write_non_print_string(t_flags *fl, int *c, va_list ap);

#endif
