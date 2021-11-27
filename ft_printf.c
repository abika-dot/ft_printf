/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:30:53 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/27 15:53:39 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		count;

	va_start(arg, s);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
			count += putchar_fd(s[i], 1);
		else if (s[i] == '%')
		{
			count += parsparam(s[i + 1], arg);
			i++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}
