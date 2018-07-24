/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtablen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:46:04 by femaury           #+#    #+#             */
/*   Updated: 2018/04/26 14:03:40 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strtablen(char **s)
{
	int		i;
	int		j;
	size_t	x;

	i = 0;
	x = 0;
	while (s[i][0])
	{
		j = 0;
		while (s[i][j])
		{
			j++;
			x++;
		}
		i++;
	}
	return (x);
}