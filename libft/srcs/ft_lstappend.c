/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:29:04 by femaury           #+#    #+#             */
/*   Updated: 2018/06/11 18:34:44 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*curr;

	curr = *alst;
	if (new && curr)
	{
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}
