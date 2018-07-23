/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:35:35 by femaury           #+#    #+#             */
/*   Updated: 2018/04/30 16:53:23 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst(t_list *lst)
{
	t_list	*curr;

	curr = lst;
	while (curr)
	{
		write(1, curr->content, curr->content_size);
		curr = curr->next;
	}
}
