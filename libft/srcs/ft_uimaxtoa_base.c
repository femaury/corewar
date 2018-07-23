/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 14:09:39 by femaury           #+#    #+#             */
/*   Updated: 2018/05/14 16:51:49 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_uimaxtoa_base(uintmax_t n, int base)
{
	int			ilen;
	char		*str;
	uintmax_t	nb;

	nb = n;
	if (base < 2 || base > 16)
		return (NULL);
	ilen = (nb == 0 ? 1 : 0);
	while (nb && ++ilen)
		nb /= base;
	if (!(str = (char *)ft_memalloc(ilen + 1)))
		return (NULL);
	while (ilen--)
	{
		str[ilen] = (n % base) + (n % base > 9 ? '7' : '0');
		n /= base;
	}
	return (str);
}
