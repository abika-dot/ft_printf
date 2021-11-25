/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsparam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 05:08:10 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/25 05:35:03 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parsparam(char c, va_list arg)
{
	if (c == 'X')
		return(hex_convert(va_arg(arg,int),1));
	else if (c == 'c')
		return(putchar(va_arg(arg,int),1));
	else if (c == 'd' || c == 'i')
		return(printnbr(va_arg(arg,int),1));
	else if (c == 'p')
		return(hex_convert((unsigned long)(va_arg(arg,void*)),2));
	else if (c == 'u')
		return (un_putnbr(va_arg(arg,int),1));
	else if (c == 'x')
	   	return (hex_convert(va_arg(arg,int),0));
	else if (c == 's')
		return (putstr_fd(va_arg(arg,char*), 1));
	else if (c == '%')
		return (putchar_fd('%', 1));
	return (0);
}
