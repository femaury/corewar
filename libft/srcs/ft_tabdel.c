/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:26:30 by femaury           #+#    #+#             */
/*   Updated: 2018/06/02 16:49:04 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(void **tab, size_t len)
{
	unsigned int	i;

	i = 0;
	if (tab)
	{
		while (i < len)
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
	}
}
