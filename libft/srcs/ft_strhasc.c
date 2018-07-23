/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhasc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:09:33 by femaury           #+#    #+#             */
/*   Updated: 2018/05/22 17:04:15 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strhasc(const char *s, int c)
{
	unsigned int	i;
	char			ch;

	i = 0;
	ch = (char)c;
	while (s[i] && s[i] != ch)
		i++;
	if (s[i] == ch)
		return (1);
	return (0);
}
