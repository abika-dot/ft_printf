/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 01:13:13 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/22 04:07:57 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

static	int parsing_middle(char c, va_list args)
{
	int				len;
	int				i;
	unsigned	int	u;
	char			*p;

	len = 0;
	if (c == 'd' || c == 'i')
	{
		i = va_arg(args, int);
		ft_putnbr_fd(i, 1);
		len = nbrlen(i);
	}
	else if (c == 's')
	{
		p = va_arg(args,char*);
		len = print(p);
	}
	else if (c == 'u')
	{
		u = va_arg(args, unsigned int);
		len = nbrlen(u);
		ft_putnbr_fd(u,1);
	}
	return (len);
}
static	int	parsing_end(char c,va_list args)
{
	int		i;
	int 	len;
	void	*p;

	len = 0;
	if(c == 'x')
	{
		i = va_arg(args,int);
		len = hex_convert(i,1);
	}
	else if (c == 'p')
	{
		p = va_arg(args, void*);
		len = hex_convert((int64_t)p,2);
	}
	return (len);
}
int parsing(char c, va_list args)
{	
	int				len;
	int				i;

	len = 0;
	if (c == '%')
	{
		ft_putchar_fd('%',1);
		len++;
	}
	else if (c == 'X')
	{
		i = va_arg(args, int);
		len = hex_convert(i,0);
	}
	else if(c == 'c')
	{
		i = va_arg(args,int);
		ft_putchar_fd(i,1);
		len++;
	}
	if (c > 'c' && c < 'x')
		return (parsing_middle(c ,args));
	else if (c >= 'x')
		return (parsing_end(c,args));
	return len;
}

