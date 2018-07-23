/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 14:09:39 by femaury           #+#    #+#             */
/*   Updated: 2018/06/07 15:49:03 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_imaxtoa_base(intmax_t n, int base)
{
	int			ilen;
	int			sign;
	char		*str;
	uintmax_t	nb;

	if (base < 2 || base > 16)
		return (NULL);
	sign = 0;
	nb = (n < 0 ? -n : n);
	ilen = (nb == 0 ? 1 : 0);
	if (n < 0)
		sign = 1;
	while (nb && ++ilen)
		nb /= base;
	if (!(str = (char *)ft_memalloc(ilen + sign + 1)))
		return (NULL);
	if (sign)
		str[0] = '-';
	nb = (n < 0 ? -n : n);
	while (ilen--)
	{
		str[ilen + sign] = (nb % base) + (nb % base > 9 ? '7' : '0');
		nb /= base;
	}
	return (str);
}
