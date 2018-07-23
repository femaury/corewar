/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:06:14 by femaury           #+#    #+#             */
/*   Updated: 2018/04/28 12:46:23 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind_size(t_list *lst, size_t ref)
{
	t_list	*curr;

	curr = lst;
	while (curr)
	{
		if (ref == curr->content_size)
			return (curr);
		curr = curr->next;
	}
	return (curr);
}
