/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrrev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:09:33 by femaury           #+#    #+#             */
/*   Updated: 2018/06/29 12:32:06 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrrev(const char *s, int c)
{
	int		i;
	char	ch;

	i = ft_strlen(s);
	ch = (char)c;
	while (i >= 0 && s[i] != ch)
		i--;
	if (s[i] == ch)
		return ((char *)(s + ++i));
	return ((char *)s);
}
