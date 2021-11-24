/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:09:05 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/22 23:22:11 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"
static int isnt(char c)
{
	if (c == '%')
		return (1);
	else if	(c == 'X')
		return (1);
	else if	(c == 'c')
		return (1);
	else if	(c == 'd')
		return (1);
	else if	(c == 'i')
		return (1);
	else if	(c == 'p')
		return (1);
	else if	(c == 'u')
		return (1);
	else if	(c == 'x')
		return (1);
	return (0);
}
static int counter(const char *s)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while(s[i])
	{
		if (s[i] && s[i] == '%' && isnt(s[i + 1]))
			count -= 2;
		i++;
		count++;
	}
	return (count);
}
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
			
		if (s[i] == '%' )
		{
			i++;
			count += parsing(s[i],args);
		}
		else
			ft_putchar_fd(s[i],1);
		i++;
	}
	va_end(args);
	return (counter(s) + count);
}
