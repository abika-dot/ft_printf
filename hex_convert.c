/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:48:41 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/23 01:21:26 by ozahir           ###   ########.fr       */
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
	hexnum = ft_calloc(17,sizeof(char));
	if (n == 0)
	{
		ft_putchar_fd('0',1);
		i++;
	}

	while(n != 0)
	{
		rem = n % 16;
		if(rem < 10)
			rem = rem + 48;
		else
			rem = rem + 55;
		if (state == 0 && (rem >= 'A' && rem <= 'Z'))
			hexnum[i] = rem + 32;
		else
			hexnum[i] = rem;
		i++;
		n = n/16;
	}
	r_print(hexnum,i - 1,state);
	free(hexnum);
	if (state == 2)
		i += 2;
	return (i);
}
