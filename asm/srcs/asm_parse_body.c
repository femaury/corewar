/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_body.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:40:56 by femaury           #+#    #+#             */
/*   Updated: 2018/09/17 20:42:51 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	find_label(t_asm_file *fl, char *ln)
{
	
	return (-2);
}

static int	find_operation(t_asm_file *fl, char *ln)
{
	int		i;
	size_t	name_len;

	i = 0;
	while (i < 16)
	{
		name_len = ft_strlen(g_op_tab[i].name);
		if (!ft_strncmp(ln + fl->ch, g_op_tab[i].name, name_len))
		{
			if (ft_iswhite(ln[fl->ch + name_len]))
				return (i);
			else if (ln[fl->ch + name_len] == LABEL_CHAR)
			{
				if (!(fl->bd.op.label = ft_memalloc(name_len + 1)))
					return (-1);
				fl->bd.op.label = ft_strcpyto(fl->bd.op.label,
						ln + fl->ch, LABEL_CHAR);
				return (0);
			}
		}
		
		i++;
	}
	return (find_label(fl, ln));
}

static int	parse_instruction(t_asm_file *fl, char *ln)
{
	while (ft_iswhite(ln[fl->ch]))
		fl->ch++;
	if (find_operation(fl, ln) < 0)
		return (exit_parsing(fl, E_BODY_BADOP));
	return (1);
}

int			parse_body(t_asm_file *fl, int fd)
{
	char	*ln;

	ln = NULL;
	fl->ch = 0;
	while (ft_gnl(fd, &ln) > 0)
	{
		if (ln[0] && !ft_striswhiteuntil(ln, COMMENT_CHAR))
		{
			if (!parse_instruction(fl, ln))
				return (0);
		}
		ft_strdel(&ln);
		fl->ln++;
	}
	return (1);
}
