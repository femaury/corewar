/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisonlyc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:54:13 by femaury           #+#    #+#             */
/*   Updated: 2018/06/03 12:56:22 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisonlyc(const char *str, const char ref)
{
	int		i;

	i = 0;
	while (str[i])
		if (str[i++] != ref)
			return (0);
	return (1);
}
