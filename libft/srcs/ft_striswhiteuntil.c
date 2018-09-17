/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striswhiteuntil.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:54:13 by femaury           #+#    #+#             */
/*   Updated: 2018/09/17 16:08:19 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_striswhiteuntil(const char *str, char ref)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != ref)
		if (!ft_iswhite(str[i++]))
			return (0);
	return (1);
}
