/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 11:55:50 by femaury           #+#    #+#             */
/*   Updated: 2018/04/19 14:55:10 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*str;

	str = (char *)b;
	while (len > 0)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (b);
}
