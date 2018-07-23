/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:53:52 by femaury           #+#    #+#             */
/*   Updated: 2018/04/21 15:57:22 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list	*cur;

	if (!lst)
		return (0);
	i = 1;
	cur = lst;
	while (cur->next)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}
