/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charrelated.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 02:14:33 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/25 05:05:59 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int 	putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6)
	}
	while (s[i])
		i += putchar_fd(&s[i], 1);
	return (i);
}
