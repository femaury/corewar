/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_body_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:51:33 by femaury           #+#    #+#             */
/*   Updated: 2018/11/12 15:25:30 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**		int		get_label(t_asm_file *fl, char *str);
**
**	Parses the label in front of an instruction. Makes sure it is properly
**	written with LABEL_CHARS ending with a LABEL_CHAR and adds it to the
**	label list at fl->bd.label.
*/

int		get_label(t_asm_file *fl, char *str)
{
	t_label	*new;

	while (str[fl->ch] && ft_strhasc(LABEL_CHARS, str[fl->ch]))
		fl->ch++;
	if (str[fl->ch] == LABEL_CHAR && !str[fl->ch + 1])
	{
		if (!(new = new_label(NULL, size_op(&fl->bd.op))))
			return (exit_parsing(fl, E_MALLOC));
		if (!(new->s = ft_memalloc(ft_strlen(str))))
			return (exit_parsing(fl, E_MALLOC));
		new->s = ft_strcpyto(new->s, str, LABEL_CHAR);
		if (fl->bd.label)
			add_label(&fl->bd.label, new);
		else
			fl->bd.label = new;
		return (1);
	}
	else
		return (exit_parsing(fl, E_BODY_LB_NAME));
}

/*
**		int		find_operation(t_asm_file *fl, char *str, t_op *op);
**
**	Looks through the g_op_tab[17] containing all valid instructions to see
**	if the one passed as parameter is one of them. Indicates in the t_op
**	structure which instruction was found.
*/

int		find_operation(t_asm_file *fl, char *str, t_op *op)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (ft_strequ(str, g_op_tab[i].name))
		{
			op->info = g_op_tab[i];
			return (1);
		}
		i++;
	}
	return (exit_parsing(fl, E_BODY_BADOP));
}
