/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:09:05 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/22 04:02:15 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"
int	ft_printf(const char *s, ...)
{
	va_list args;
	int	i;
	int count;

	va_start(args,s);	
	count = 0;
	i = 0;
	while(s[i])
	{	
		if (s[i] == '%')
		{
			count = parsing(s[i + 1],args);
		}
		else
			ft_putchar_fd(s[i],1);
		i++;
	}
	va_end(args);
	return (count + i);
}
