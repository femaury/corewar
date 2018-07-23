/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:05:10 by femaury           #+#    #+#             */
/*   Updated: 2018/06/01 19:28:19 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_sqrt(float nbr)
{
	float tmp;
	float res;

	res = nbr / 2;
	tmp = 0;
	while (res != tmp)
	{
		tmp = res;
		res = ((nbr / tmp + tmp) / 2);
	}
	return (res);
}
