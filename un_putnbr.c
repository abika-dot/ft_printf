/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   un_ft_putnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:21:56 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/22 22:41:20 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"
int un_putnbr(unsigned int nb, int fd)
{
	unsigned	int	a;
	int				len;

	a = nb;
	if (a > 9)
	{
		ft_putnbr_fd(a / 10, fd);
		ft_putnbr_fd(a % 10, fd);
	}
	else
		ft_putchar_fd(a + '0', fd);
	len = 0;
	if (nb == 0)
		len = 1;
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}
