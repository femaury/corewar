/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_body.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:40:56 by femaury           #+#    #+#             */
/*   Updated: 2018/11/12 16:02:52 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**		char	*prepare_label(t_asm_file *fl, char *ln);
**
**	Receives a string containing a label. Checks that it is just a label,
**	that it uses only LABEL_CHARS and is properly finished with a LABEL_CHAR.
**	Trims the whitespace and returns the new string.
*/

static char	*prepare_label(t_asm_file *fl, char *ln)
{
	while (ft_iswhite(ln[fl->ch]))
		fl->ch++;
	while (ft_strhasc(LABEL_CHARS, ln[fl->ch]))
		fl->ch++;
	if (ln[fl->ch] == LABEL_CHAR
			&& ft_striswhiteuntil(ln + fl->ch + 1, COMMENT_CHAR))
	{
		ft_strclr(ln + fl->ch + 1);
		fl->ch = 0;
		return (ft_strtrim(ln));
	}
	return (NULL);
}

/*
**		char	**prepare_params(char *ln, int nb);
**
**	Takes a string containing an instruction and its parameters, skips
**	the label and/or instruction part to keep a string with only the params
**	and then removes all white space from that string. The resulting string
**	is the split according to the SEPAR_CHAR into a table of all the params.
**	If a param contains a COMMENT_CHAR, every character and string in the
**	table folllowng it is deleted. Returns the table.
*/

static char	**prepare_params(char *ln, int nb)
{
	char			*trimmed;
	char			**params;
	unsigned int	i;
	unsigned int	kill;

	i = 0;
	kill = 0;
	if (!(trimmed = ft_strstrip(ft_skipnwhite(ln, nb))))
		return (NULL);
	if (!(params = ft_strsplit(trimmed, SEPAR_CHAR)))
		return (NULL);
	ft_strdel(&trimmed);
	while (params[i])
	{
		if (kill)
			ft_strdel(&params[i]);
		if (ft_strhasc(params[i], COMMENT_CHAR))
		{
			ft_strclrfrom(params[i], COMMENT_CHAR);
			kill = 1;
		}
		i++;
	}
	return (params);
}

/*
**		int		parse_instruction(t_asm_file *fl, char *ln, t_op *op);
**
**	Takes the line containing a possible instruction, then splits it at the
**	white spaces to separate label, instruction and params. If there is a
**	label (found with LABEL_CHAR), parses that first. Then either way, the
**	function gets the instruction followed by its parameters.
*/

static int	parse_instruction(t_asm_file *fl, char *ln, t_op *op)
{
	char	**table;

	table = ft_splitwhite(ln);
	fl->ch = 0;
	if (ft_strhasc(table[0], LABEL_CHAR))
	{
		if (get_label(fl, table[0]) && find_operation(fl, table[1], op)
				&& get_params(fl, prepare_params(ln, 2),
				ft_strcountc(ln, SEPAR_CHAR), op))
		{
			ft_tabdel((void **)table, ft_strtabsize(table));
			return (1);
		}
	}
	else
	{
		if (find_operation(fl, table[0], op) && get_params(fl,
				prepare_params(ln, 1), ft_strcountc(ln, SEPAR_CHAR), op))
		{
			ft_tabdel((void **)table, ft_strtabsize(table));
			return (1);
		}
	}
	return (0);
}

/*
**		int		parse_body_ext(t_asm_file *fl, char *ln);
**
**					Extends parse_body().
**	Creates a new t_op structure to keep all the instruction data
**	parsed in parse_instruction(). Appends the new structure to the
**	list in fl->bd.op.
*/

static int	parse_body_ext(t_asm_file *fl, char *ln)
{
	t_op	*new;

	if (!(new = new_op()))
		return (exit_parsing(fl, E_MALLOC));
	if (!parse_instruction(fl, ln, new))
		return (0);
	new->line = fl->ln;
	if (!fl->bd.op)
		fl->bd.op = new;
	else
		add_op(&fl->bd.op, new);
	return (1);
}

/*
**		int		parse_body(t_asm_file *fl, int fd);
**
**	Iterates with ft_gnl() through the rest of the file looking for
**	a line that contains something other than a comment. Once found,
**	it checks wether that line is solely a label or if it also might
**	contain instructions. After getting through the whole file without
**	raising an error, the function calculates the total size of the
**	instructions and then returns TRUE.
*/

int			parse_body(t_asm_file *fl, int fd)
{
	char	*ln;
	char	*tmp;

	ln = NULL;
	while (!(fl->status = 0) && ft_gnl(fd, &ln) > 0)
	{
		fl->ch = 0;
		if (ln[0] && !ft_striswhiteuntil(ln, COMMENT_CHAR))
		{
			if ((tmp = prepare_label(fl, ln)))
			{
				if (!get_label(fl, tmp))
					return (0);
				ft_strdel(&tmp);
			}
			else
			{
				if (!parse_body_ext(fl, ln))
					return (0);
			}
		}
		fl->ln++ ? ft_strdel(&ln) : ft_strdel(&ln);
	}
	fl->bd.op_size = ft_revbits(size_op(&fl->bd.op));
	return (1);
}
