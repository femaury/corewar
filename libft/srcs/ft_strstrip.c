/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:54:49 by femaury           #+#    #+#             */
/*   Updated: 2018/09/19 17:11:06 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstrip(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	char			*new;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (s[i])
		if (!ft_iswhite(s[i++]))
			len++;
	if (!(new = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (!ft_iswhite(s[i]))
			new[j++] = s[i];
		i++;
	}
	new[j] = '\0';
	return (new);
}
