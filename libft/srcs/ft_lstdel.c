/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:21:49 by femaury           #+#    #+#             */
/*   Updated: 2018/06/12 12:15:46 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst)
{
	if (!*alst)
		return ;
	ft_lstdel(&(*alst)->next);
	ft_memdel(&(*alst)->content);
	free(*alst);
	*alst = NULL;
}
