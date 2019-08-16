/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_safe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:31:57 by cpoirier          #+#    #+#             */
/*   Updated: 2018/12/14 10:27:54 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_SAFE_H
# define STR_SAFE_H

char		*ft_strnew_safe(int len);
char		*ft_strdup_safe(const char *s);
char		get_safe_digit(long long l);

#endif
