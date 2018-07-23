/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:40:54 by femaury           #+#    #+#             */
/*   Updated: 2018/06/15 19:23:05 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_strcount(char const *s, char c)
{
	unsigned int	i;
	unsigned int	strings;

	i = 0;
	strings = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i])
				i++;
			strings++;
		}
	}
	return (strings);
}

static unsigned int	ft_charcount(char const *s, char c, unsigned int j)
{
	unsigned int	i;

	i = 0;
	while (s[j] != c && s[j])
	{
		j++;
		i++;
	}
	return (i);
}

static char			**ft_filltab(char **strtab, char const *s, char c,
		unsigned int strcount)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	while (i < strcount)
	{
		while (s[j] == c)
			j++;
		if (s[j] != '\0')
		{
			if (!(strtab[i] = (char *)malloc(ft_charcount(s, c, j) + 1)))
				return (NULL);
			k = 0;
			while (s[j] != c && s[j])
				strtab[i][k++] = s[j++];
			strtab[i][k] = '\0';
			while (s[j] != c && s[j])
				j++;
		}
		i++;
	}
	return (strtab);
}

char				**ft_strsplit(char const *s, char c)
{
	unsigned int	strcount;
	char			**strtab;

	if (!s)
		return (NULL);
	strcount = ft_strcount(s, c);
	if (!(strtab = (char **)malloc(sizeof(char *) * (strcount + 1))))
		return (NULL);
	strtab = ft_filltab(strtab, s, c, strcount);
	strtab[strcount] = NULL;
	return (strtab);
}
