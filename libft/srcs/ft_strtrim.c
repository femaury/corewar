/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:54:49 by femaury           #+#    #+#             */
/*   Updated: 2018/04/20 17:58:26 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_strtrim_len(char const *s)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;

	i = 0;
	start = 0;
	end = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (!s[i])
		return (0);
	start = i;
	while (s[i])
		i++;
	i -= 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	end = i;
	return ((end - start) + 1);
}

char				*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	char			*new;

	if (!s)
		return (NULL);
	len = ft_strtrim_len(s);
	if (!(new = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (j < len)
		new[j++] = s[i++];
	new[j] = '\0';
	return (new);
}
