/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdellast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:12:39 by femaury           #+#    #+#             */
/*   Updated: 2018/06/18 20:33:46 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstdellast(t_list **alst)
{
	if (!*alst)
		return (1);
	if (ft_lstdellast(&(*alst)->next))
	{
		ft_memdel((&(*alst)->content));
		free(*alst);
		*alst = NULL;
	}
	return (0);
}
