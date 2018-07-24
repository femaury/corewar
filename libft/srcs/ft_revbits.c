/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:45:34 by femaury           #+#    #+#             */
/*   Updated: 2018/07/24 15:47:15 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	revbits(unsigned int x)
{
	return ((x << 24) | (( x & 0xff00 ) << 8)
			| (( x >> 8) & 0xff00 ) | ( x >> 24 ));
}