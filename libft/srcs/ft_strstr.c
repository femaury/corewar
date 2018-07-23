/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:20:26 by femaury           #+#    #+#             */
/*   Updated: 2018/04/19 18:09:55 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (ft_strlen((char *)needle) == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] &&
					needle[j] && haystack[i + j])
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
