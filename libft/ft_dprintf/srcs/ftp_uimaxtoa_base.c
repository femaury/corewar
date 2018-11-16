/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_uimaxtoa_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 14:09:39 by femaury           #+#    #+#             */
/*   Updated: 2018/09/25 17:56:21 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftdprintf.h"

char		*ftp_uimaxtoa_base(uintmax_t n, int base)
{
	int			ilen;
	static char	str[21];
	uintmax_t	nb;

	nb = n;
	if (base < 2 || base > 16)
		return (NULL);
	ilen = (nb == 0 ? 1 : 0);
	while (nb && ++ilen)
		nb /= base;
	str[ilen] = '\0';
	while (ilen--)
	{
		str[ilen] = (n % base) + (n % base > 9 ? '7' : '0');
		n /= base;
	}
	return (str);
}
