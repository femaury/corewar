/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:50:38 by femaury           #+#    #+#             */
/*   Updated: 2018/06/18 19:45:04 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_split(char const *s1, char const *s2, char split)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	if (!(i = 0) && !s1)
		return (ft_strdup(s2));
	if (!(j = 0) && !s2)
		return ((char *)s1);
	if (!(new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2)))
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i++] = split;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}
