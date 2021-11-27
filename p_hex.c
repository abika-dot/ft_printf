/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:41:45 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/27 16:09:33 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 20:20:11 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/27 15:41:16 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	pointerp(unsigned long int nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += pointerp(nb / 16);
		len += pointerp(nb % 16);
	}
	else if (nb > 9)
		len += putchar_fd(nb + 87, 1);
	else
		len += putchar_fd(nb + '0', 1);
	return (len);
}

int	hex_convert(unsigned int nb, int state)
{
	int	len;
	int	stating;

	stating = 0;
	len = 0;
	if (state == 1)
		stating = -32;
	if (nb >= 16)
	{
		len += hex_convert(nb / 16, state);
		len += hex_convert(nb % 16, state);
	}
	else if (nb > 9)
		len += putchar_fd(nb + 87 + stating, 1);
	else
		len += putchar_fd(nb + '0', 1);
	return (len);
}
