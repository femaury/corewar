/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupto.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:33:53 by femaury           #+#    #+#             */
/*   Updated: 2018/06/09 17:29:53 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupto(const char *s1, char ref)
{
	char	*cpy;
	size_t	len;

	len = 0;
	while (s1[len] && s1[len] != ref)
		len++;
	if (!(cpy = (char *)malloc(len + 1)))
		return (NULL);
	cpy = ft_strncpy(cpy, s1, len);
	cpy[len] = '\0';
	return (cpy);
}
