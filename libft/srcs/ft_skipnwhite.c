/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipnwhite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 22:22:16 by femaury           #+#    #+#             */
/*   Updated: 2018/09/19 17:04:41 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_skipnwhite(char *str, int nb)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_iswhite(str[i]))
		{
			if (j == nb)
				return (str + i);
			while (str[i] && !ft_iswhite(str[i]))
				i++;
			j++;
		}
		else
			i++;
	}
	return (str);
}
