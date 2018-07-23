/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:33:53 by femaury           #+#    #+#             */
/*   Updated: 2018/04/30 15:31:36 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char	*cpy;

	if (!(cpy = (char *)malloc(len + 1)))
		return (NULL);
	return (ft_strncpy(cpy, s1, len));
}
