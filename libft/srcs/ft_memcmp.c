/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:24:17 by femaury           #+#    #+#             */
/*   Updated: 2018/04/20 18:10:40 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	unsigned const char	*cs1;
	unsigned const char	*cs2;

	i = 0;
	cs1 = (unsigned const char *)s1;
	cs2 = (unsigned const char *)s2;
	while (i < n && cs1[i] == cs2[i])
		i++;
	return (i == n) ? (0) : (cs1[i] - cs2[i]);
}
