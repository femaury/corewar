/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 20:14:05 by femaury           #+#    #+#             */
/*   Updated: 2018/05/12 21:23:09 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_setupcase(char *s)
{
	while (*s)
	{
		if (ft_islower(*s))
			*s -= 32;
		s++;
	}
}
