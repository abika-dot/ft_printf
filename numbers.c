/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:55:57 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/27 16:11:33 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbrlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	printnbr(int nb, int fd)
{
	long	a;

	a = nb;
	if (nb < 0)
	{
		putchar_fd('-', fd);
		a *= -1;
	}
	if (a > 9)
	{
		printnbr(a / 10, fd);
		printnbr(a % 10, fd);
	}
	else
		putchar_fd(a + '0', fd);
	return (nbrlen(nb));
}

int	un_putnbr(unsigned int nb, int fd)
{
	unsigned int	a;
	int				len;

	a = nb;
	if (a > 9)
	{
		un_putnbr(a / 10, fd);
		un_putnbr(a % 10, fd);
	}
	else
		putchar_fd(a + '0', fd);
	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}
