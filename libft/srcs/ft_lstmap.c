/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:38:26 by femaury           #+#    #+#             */
/*   Updated: 2018/04/20 13:29:46 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*new_hd;

	if (!lst)
		return (NULL);
	new_lst = (*f)(lst);
	new_hd = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst->next = (*f)(lst);
		new_lst = new_lst->next;
		lst = lst->next;
	}
	return (new_hd);
}
