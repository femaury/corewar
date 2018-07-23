/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:33:53 by femaury           #+#    #+#             */
/*   Updated: 2018/04/18 14:37:02 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;

	if (!(cpy = (char *)malloc(ft_strlen(s1) + 1)))
		return (NULL);
	return (ft_strcpy(cpy, s1));
}
