/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:20:47 by femaury           #+#    #+#             */
/*   Updated: 2018/04/20 15:42:15 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdst;
	char	*csrc;

	cdst = (char *)dst;
	csrc = (char *)src;
	if (src < dst)
		while (len > 0)
		{
			*(cdst + (len - 1)) = *(csrc + (len - 1));
			len--;
		}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
