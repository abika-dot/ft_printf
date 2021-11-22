/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:10:42 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/17 05:34:52 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	b;

	i = ft_strlen(s);
	b = i;
	while (i != 0)
	{
		if (s[i] == c)
			return ((char *)(&s[i]));
		i--;
	}
	if (s[i] == (char )c)
		return ((char *)(&s[i]));
	return (NULL);
}
