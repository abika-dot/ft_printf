/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:38:21 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/27 15:54:32 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		parsparam(char c, va_list arg);
int		putchar_fd(char c, int fd);
int		putstr_fd(char *s, int fd);
int		hex_convert(unsigned int n, int state);
int		printnbr(int nb, int fd);
int		un_putnbr(unsigned int nb, int fd);
int		pointerp(unsigned long int nb);

#endif
