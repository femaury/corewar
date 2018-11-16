/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lablist_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:43:17 by femaury           #+#    #+#             */
/*   Updated: 2018/09/24 16:35:34 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label	*new_label(char *label, unsigned size)
{
	t_label	*new;

	if (!(new = (t_label *)malloc(sizeof(t_label))))
		return (NULL);
	new->s = label;
	new->size = size;
	new->next = NULL;
	return (new);
}

void	add_label(t_label **head, t_label *new)
{
	t_label	*curr;

	curr = *head;
	if (new && curr)
	{
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}

int		get_label_size(t_label **head, char *label)
{
	t_label *curr;

	curr = *head;
	while (curr)
	{
		if (ft_strequ(curr->s, label))
			return ((int)curr->size);
		curr = curr->next;
	}
	return (-1);
}

int		check_labels(t_asm_file *fl, t_op **ophd, t_label **labhd)
{
	unsigned int	i;
	t_op			*curr;
	t_label			*check;

	curr = *ophd;
	while ((i = -1) && curr)
	{
		while (++i < 3)
			if (curr->params[i].label)
			{
				check = *labhd;
				while (check)
				{
					if (ft_strequ(check->s, curr->params[i].label))
						break ;
					check = check->next;
				}
				if (!check)
					return (!(fl->ln = curr->line));
			}
		curr = curr->next;
	}
	return (1);
}
