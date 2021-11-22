/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:48:41 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/22 04:03:26 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

static	void r_print(char *s,int len ,int state)
{
	if (state == 2)
	{
		ft_putchar_fd('0',1);
		ft_putchar_fd('x',1);
	}
	while(len != -1)
	{
		if (state == 1 && (s[len] >= '0' && s[len] <= '9'))
			s[len] += 32;
		ft_putchar_fd(s[len],1);	
		len--;
	}
}
int	hex_convert(unsigned int n, int state)
{
	int		i;
	int		rem;
	char	*hexnum;

	i = 0;
	rem = 0;
	hexnum = ft_calloc(9,sizeof(char));
	while(n != 0)
	{
		rem = n % 16;
		if(rem < 10)
			rem = rem+48;
		else
			rem = rem+55;
		hexnum[i] = rem;
		i++;
		n = n/16;
	}
	r_print(hexnum,i,state);
	if (state == 2)
		i += 2;
	return (i);
}
