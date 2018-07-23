/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:41:47 by femaury           #+#    #+#             */
/*   Updated: 2018/04/19 18:10:28 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (ft_strlen((char *)needle) == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && needle[j] &&
				haystack[i + j] && (i + j) < len)
				j++;
			if (!needle[j])
				return ((char *)haystack + i);
			if (!haystack[i + j])
				return (NULL);
		}
		i++;
	}
	return (NULL);
}
