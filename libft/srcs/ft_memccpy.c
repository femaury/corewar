/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:53:12 by femaury           #+#    #+#             */
/*   Updated: 2018/04/20 18:25:17 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dstcpy;
	unsigned char	*srccpy;

	i = 0;
	if (n == 0)
		return (NULL);
	dstcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	while (i < n)
	{
		dstcpy[i] = srccpy[i];
		if (srccpy[i] == (unsigned char)c)
			return (dstcpy + (i + 1));
		i++;
	}
	return (NULL);
}
