/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:56:49 by femaury           #+#    #+#             */
/*   Updated: 2018/04/21 15:05:43 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstsize;
	size_t	srcsize;

	i = 0;
	dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	if (!size)
		return (srcsize);
	if (dstsize >= size)
		return (size + srcsize);
	if (srcsize < size - dstsize)
		ft_strncat(dst, src, srcsize + 1);
	else
	{
		ft_strncat(dst, src, size - dstsize - 1);
		dst[size - 1] = '\0';
	}
	return (dstsize + srcsize);
}
