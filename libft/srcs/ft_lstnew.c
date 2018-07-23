/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:06:58 by femaury           #+#    #+#             */
/*   Updated: 2018/05/09 12:01:00 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	unsigned int	i;
	t_list			*new;

	i = 0;
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content && content_size)
	{
		if (!(new->content = malloc(content_size)))
			return (NULL);
		while (i < content_size)
		{
			*(char *)(new->content + i) = *(char *)(content + i);
			i++;
		}
		new->content_size = content_size;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->content_ptr = new->content;
	new->next = NULL;
	return (new);
}
