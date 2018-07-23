/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:09:39 by femaury           #+#    #+#             */
/*   Updated: 2018/04/23 11:18:59 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ilen(int n)
{
	int	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	int		ilen;
	int		sign;
	char	*str;

	sign = n < 0 ? 1 : 0;
	ilen = ft_ilen(n);
	if (!(str = (char *)ft_memalloc(ilen + sign + 1)))
		return (NULL);
	if (sign)
		str[0] = '-';
	while (ilen--)
	{
		str[ilen + sign] = (sign ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
	}
	return (str);
}
