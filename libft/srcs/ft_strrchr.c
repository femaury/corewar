/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:15:56 by femaury           #+#    #+#             */
/*   Updated: 2018/04/18 20:44:40 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = (int)ft_strlen(s);
	ch = (char)c;
	while (i >= 0 && s[i] != ch)
		i--;
	if (s[i] == ch)
		return ((char *)(s + i));
	return (NULL);
}
