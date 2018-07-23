/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisonly.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:54:13 by femaury           #+#    #+#             */
/*   Updated: 2018/05/29 12:52:59 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisonly(const char *str, const char *ref)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (ref[j])
		{
			if (str[i] == ref[j])
				break ;
			j++;
			if (!ref[j])
				return (0);
		}
		i++;
	}
	return (1);
}
