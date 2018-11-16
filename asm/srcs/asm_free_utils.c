/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_free_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:25:41 by femaury           #+#    #+#             */
/*   Updated: 2018/11/12 15:57:06 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			free_params(int ret, char **params, size_t size)
{
	ft_tabdel((void **)params, size);
	return (ret);
}

void		free_labels(t_label **lst)
{
	if (!*lst)
		return ;
	free_labels(&(*lst)->next);
	ft_strdel(&(*lst)->s);
	free(*lst);
	*lst = NULL;
}

void		free_ops(t_op **lst)
{
	int	i;

	i = 0;
	if (!*lst)
		return ;
	free_ops(&(*lst)->next);
	while (i < 3)
	{
		if ((*lst)->params[i].label)
			ft_strdel(&(*lst)->params[i].label);
		i++;
	}
	free(*lst);
	*lst = NULL;
}
