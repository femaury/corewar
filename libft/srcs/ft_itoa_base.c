/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 14:09:39 by femaury           #+#    #+#             */
/*   Updated: 2018/05/30 17:33:26 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_power(long n, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (n * ft_power(n, power - 1));
}

char		*ft_itoa_base(int n, int base)
{
	int		ilen;
	int		sign;
	char	*str;
	long	nb;

	nb = (long)n;
	if (base < 2 || base > 16)
		return (NULL);
	sign = (nb < 0 && base == 10) ? 1 : 0;
	if (nb < 0)
		nb = -nb;
	ilen = 1;
	while (nb > ft_power((long)base, ilen) - 1)
		ilen++;
	if (!(str = (char *)ft_memalloc(ilen + sign + 1)))
		return (NULL);
	if (sign)
		str[0] = '-';
	while (ilen--)
	{
		str[ilen + sign] = (nb % base) + (nb % base > 9 ? '7' : '0');
		nb /= base;
	}
	return (str);
}
