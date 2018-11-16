/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitwhite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:40:54 by femaury           #+#    #+#             */
/*   Updated: 2018/09/18 15:14:03 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_strcount(char const *s)
{
	unsigned int	i;
	unsigned int	strings;

	i = 0;
	strings = 0;
	while (s[i])
	{
		if (ft_iswhite(s[i]))
			i++;
		else
		{
			while (s[i] && !ft_iswhite(s[i]))
				i++;
			strings++;
		}
	}
	return (strings);
}

static unsigned int	ft_charcount(char const *s, unsigned int j)
{
	unsigned int	i;

	i = 0;
	while (!ft_iswhite(s[j]) && s[j])
	{
		j++;
		i++;
	}
	return (i);
}

static char			**ft_filltab(char **strtab, char const *s,
		unsigned int strcount)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	while (i < strcount)
	{
		while (ft_iswhite(s[j]))
			j++;
		if (s[j] != '\0')
		{
			if (!(strtab[i] = (char *)malloc(ft_charcount(s, j) + 1)))
				return (NULL);
			k = 0;
			while (!ft_iswhite(s[j]) && s[j])
				strtab[i][k++] = s[j++];
			strtab[i][k] = '\0';
			while (!ft_iswhite(s[j]) && s[j])
				j++;
		}
		i++;
	}
	return (strtab);
}

char				**ft_splitwhite(char const *s)
{
	unsigned int	strcount;
	char			**strtab;

	if (!s)
		return (NULL);
	strcount = ft_strcount(s);
	if (!(strtab = (char **)malloc(sizeof(char *) * (strcount + 1))))
		return (NULL);
	strtab = ft_filltab(strtab, s, strcount);
	strtab[strcount] = NULL;
	return (strtab);
}
