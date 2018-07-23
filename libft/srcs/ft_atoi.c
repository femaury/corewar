/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:56:11 by femaury           #+#    #+#             */
/*   Updated: 2018/04/20 16:27:03 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned int	i;
	unsigned int	sign;
	int				ans;

	i = 0;
	sign = 1;
	ans = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && str[i])
		i++;
	if (str[i] == '-')
	{
		i++;
		sign = 0;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		ans = ans * 10 + (str[i++] - '0');
	return (sign) ? (ans) : (-ans);
}
