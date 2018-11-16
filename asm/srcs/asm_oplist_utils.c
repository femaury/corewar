/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_oplist_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:43:17 by femaury           #+#    #+#             */
/*   Updated: 2018/09/20 17:15:42 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	*new_op(void)
{
	t_op			*new;
	unsigned int	i;

	i = 0;
	if (!(new = (t_op *)malloc(sizeof(t_op))))
		return (NULL);
	new->size = 0;
	new->line = 0;
	while (i < 3)
	{
		new->params[i].label = NULL;
		new->params[i].type = 0;
		new->params[i].size = 0;
		new->params[i].value = 0;
		i++;
	}
	new->next = NULL;
	return (new);
}

void	add_op(t_op **head, t_op *new)
{
	t_op	*curr;

	curr = *head;
	if (new && curr)
	{
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}

int		size_op(t_op **head)
{
	int		size;
	t_op	*curr;

	size = 0;
	curr = *head;
	while (curr)
	{
		size += curr->size;
		curr = curr->next;
	}
	return (size);
}

int		sizeto_op(t_op **head, t_op *ref)
{
	int		size;
	t_op	*curr;

	size = 0;
	curr = *head;
	while (curr)
	{
		if (curr == ref)
			break ;
		size += curr->size;
		curr = curr->next;
	}
	return (size);
}
