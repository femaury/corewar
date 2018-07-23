/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_uimaxtoa_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 14:09:39 by femaury           #+#    #+#             */
/*   Updated: 2018/05/21 15:07:02 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
