/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 02:59:47 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/25 05:05:42 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int r_print(char *s, int len, int state)
{
	int i;

	i = 0;
	if (state == 2)
	{
		i += putchar_fd('0',1);
		i += putchar_fd('x',1);
	}
	while(len != -1)
	{
		if (state == 1 && s[len] > "9")
			s[len] -= 32;
		ft_putchar_fd(s[len],1);	
		len--;
		i++;
	}
	return (i);
}
static int	h_nbrlen(unsigned long n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	hex_convert(unsigned long n, int state)
{
	char				*s;
	int					i;
	unsigned	long		rem;
	
	rem = n;
	s = malloc((h_nbrlen(n) + 1) * sizeof(char));
	i = 0;
	while (n)
	{
		rem = n % 16;
		n = n / 16;
		if ( rem >= 0 && rem <= 9)
			rem += '0';
		else if (rem > 9)
			rem += 55;
		s[i] = rem;
		i++;
	}
	s[i] = 0;
	return (r_print(s,i - 1 ,state));
}
