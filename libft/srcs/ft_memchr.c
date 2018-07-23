/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:14:20 by femaury           #+#    #+#             */
/*   Updated: 2018/04/20 17:31:12 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*cs;

	i = 0;
	cs = (unsigned char *)s;
	while (i < n)
	{
		if (cs[i] == (unsigned char)c)
			return ((void *)cs + i);
		i++;
	}
	return (NULL);
}
