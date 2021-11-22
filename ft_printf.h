/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 02:52:27 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/22 03:55:50 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	nbrlen(int n);
int	hex_convert(unsigned int n, int state);
int parsing(char c, va_list args);
int print(char *s);

#endif
