/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:12:39 by femaury           #+#    #+#             */
/*   Updated: 2018/06/12 11:36:20 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelfirst(t_list **alst)
{
	t_list	*todel;

	todel = *alst;
	if (todel)
	{
		*alst = (*alst)->next;
		free(todel->content);
		free(todel);
		todel = NULL;
	}
}
