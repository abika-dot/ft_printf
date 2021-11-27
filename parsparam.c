/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsparam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 05:08:10 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/27 16:04:27 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	parsparam(char c, va_list arg)
{
	if (c == 'X')
		return (hex_convert(va_arg(arg, int), 1));
	else if (c == 'c')
		return (putchar_fd(va_arg(arg, int), 1));
	else if (c == 'd' || c == 'i')
		return (printnbr(va_arg(arg, int), 1));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		return (2 + (pointerp((unsigned long int)(va_arg(arg, void *)))));
	}
	else if (c == 'u')
		return (un_putnbr(va_arg(arg, int), 1));
	else if (c == 'x')
		return (hex_convert(va_arg(arg, int), 0));
	else if (c == 's')
		return (putstr_fd(va_arg(arg, char *), 1));
	else if (c == '%')
		return (putchar_fd('%', 1));
	return (0);
}
