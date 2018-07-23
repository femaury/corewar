/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:03:57 by femaury           #+#    #+#             */
/*   Updated: 2018/06/15 19:25:25 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list **alst)
{
	t_list	*new;
	t_list	*curr;

	new = NULL;
	curr = *alst;
	if (curr)
	{
		if (!(new = ft_lstnew(curr->content, curr->content_size)))
			return (NULL);
		curr = curr->next;
	}
	while (curr)
	{
		ft_lstappend(&new, ft_lstnew(curr->content, curr->content_size));
		curr = curr->next;
	}
	return (new);
}
