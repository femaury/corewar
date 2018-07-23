/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:09:33 by femaury           #+#    #+#             */
/*   Updated: 2018/04/18 20:51:35 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			ch;

	i = 0;
	ch = (char)c;
	while (s[i] && s[i] != ch)
		i++;
	if (s[i] == ch)
		return ((char *)(s + i));
	if (ch == '\0' && s[i + 1] == '\0')
		return ((char *)(s + (i + 1)));
	return (NULL);
}
