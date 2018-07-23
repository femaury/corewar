/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:50:38 by femaury           #+#    #+#             */
/*   Updated: 2018/06/15 18:51:25 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	if (!s1)
	{
		if (!(new = (char *)malloc(len + 1)))
			return (NULL);
		return (ft_strndup(s2, len));
	}
	if (!s2 || !len)
		return ((char *)s1);
	if (!(new = (char *)malloc(ft_strlen(s1) + len + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] && j < len)
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}
