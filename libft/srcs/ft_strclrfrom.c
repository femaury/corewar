/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclrfrom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:56:00 by femaury           #+#    #+#             */
/*   Updated: 2018/09/20 17:59:22 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclrfrom(char *str, char ref)
{
	unsigned int i;
	unsigned int clr;

	i = 0;
	clr = 0;
	while (str[i])
	{
		if (str[i] == ref)
			clr = 1;
		if (clr)
			str[i] = '\0';
		i++;
	}
}
