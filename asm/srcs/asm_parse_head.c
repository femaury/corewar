/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 22:24:31 by femaury           #+#    #+#             */
/*   Updated: 2018/09/25 18:03:27 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**		int		parse_name_multi_ln(t_asm_file *fl, char *ln, int fd);
**
**			  -- CHECK parse_comment_multi_ln() COMMENT BELOW --
*/

static int	parse_name_multi_ln(t_asm_file *fl, char *ln, int fd)
{
	fl->ch = 0;
	ft_strcat(fl->hd.prog_name, "\n");
	while (++fl->ln && ft_gnl(fd, &ln) > 0 && !ft_strhasc(ln, '"'))
	{
		if (ft_strlen(ln) + ft_strlen(fl->hd.prog_name) > PROG_NAME_LENGTH)
			return (exit_parsing(fl, E_NAME_LEN));
		ft_strcat(fl->hd.prog_name, ln);
		ft_strcat(fl->hd.prog_name, "\n");
		ft_strdel(&ln);
	}
	if (!ln || !ft_strhasc(ln, '"'))
		return (exit_parsing(fl, E_NAME_NOEND));
	while (ln[fl->ch] != '"')
		fl->ch++;
	if (ft_strlen(fl->hd.prog_name) + fl->ch > PROG_NAME_LENGTH)
		return (exit_parsing(fl, E_NAME_LEN));
	if (ln[++fl->ch])
		while (ln[fl->ch] && ln[fl->ch] != COMMENT_CHAR)
			if (!ft_iswhite(ln[fl->ch++]))
				return (exit_parsing(fl, E_NAME_EXTRA));
	ft_strcatto(fl->hd.prog_name, ln, '"');
	ft_strdel(&ln);
	return (1);
}

/*
**		int		parse_name(t_asm_file *fl, char *ln, int fd);
**
**			  -- CHECK parse_comment() COMMENT BELOW --
*/

static int	parse_name(t_asm_file *fl, char *ln, int fd)
{
	fl->ch = ft_strlen(NAME_CMD_STR);
	while (ln[fl->ch] && ln[fl->ch] != '"')
		if (!ft_iswhite(ln[fl->ch++]))
			return (exit_parsing(fl, E_NAME_OPEN));
	fl->ch++;
	ft_strcpyto(fl->hd.prog_name, ln + fl->ch, '"');
	if (ft_strlen(fl->hd.prog_name) > PROG_NAME_LENGTH)
		return (exit_parsing(fl, E_NAME_LEN));
	fl->ch += ft_strlen(fl->hd.prog_name);
	if (ln[fl->ch] == '"')
	{
		if (ln[++fl->ch])
			while (ln[fl->ch] && ln[fl->ch] != COMMENT_CHAR)
				if (!ft_iswhite(ln[fl->ch++]))
					return (exit_parsing(fl, E_NAME_EXTRA));
	}
	else
	{
		if (!parse_name_multi_ln(fl, ln, fd))
			return (0);
	}
	fl->status |= S_NAME;
	return (1);
}

/*
**		int		parse_comment_multi_ln(t_asm_file *fl, char *ln, int fd);
**
**	1 - Iterates with ft_gnl() until a closing quote or EOF. For each line,
**		check if said line would make total comment lenght too long, then adds
**		it to fl->hd.comment followed by a newline.
**
**	2 - If while loop is left with a NULL ln or without having found a closing
**		quote, exits the parsing. Otherwise keeps fl->ch up to date and checks
**		if last line will make comment too long.
**
**	3 - Filters trailing characters for anything other than whitespace and
**		comments (using COMMENT_CHAR). Then adds last line to fl->hd.comment.
*/

static int	parse_comment_multi_ln(t_asm_file *fl, char *ln, int fd)
{
	fl->ch = 0;
	ft_strcat(fl->hd.comment, "\n");
	while (++fl->ln && ft_gnl(fd, &ln) > 0 && !ft_strhasc(ln, '"'))
	{
		if (ft_strlen(ln) + ft_strlen(fl->hd.comment) > COMMENT_LENGTH)
			return (exit_parsing(fl, E_COMM_LEN));
		ft_strcat(fl->hd.comment, ln);
		ft_strcat(fl->hd.comment, "\n");
		ft_strdel(&ln);
	}
	if (!ln || !ft_strhasc(ln, '"'))
		return (exit_parsing(fl, E_COMM_NOEND));
	while (ln[fl->ch] != '"')
		fl->ch++;
	if (ft_strlen(fl->hd.comment) + fl->ch > COMMENT_LENGTH)
		return (exit_parsing(fl, E_COMM_LEN));
	if (ln[++fl->ch])
		while (ln[fl->ch] && ln[fl->ch] != COMMENT_CHAR)
			if (!ft_iswhite(ln[fl->ch++]))
				return (exit_parsing(fl, E_COMM_EXTRA));
	ft_strcatto(fl->hd.comment, ln, '"');
	ft_strdel(&ln);
	return (1);
}

/*
**		int		parse_comment(t_asm_file *fl, char *ln, int fd);
**
**	fl->ch keeps track (not perfectly) of current character for debugging.
**
**	1 - Skips all whitespace after comm command until opening double quote is
**		found. Otherwise exits parsing.
**
**	2 - Checks if first comment line will exceed COMMENT_LENGTH and if yes exits
**		parsing.
**
**	3 - Copies the characters into fl->hd.comment until either closing quote or
**		end of line. Adds lenght of copied string into fl->ch.
**
**	4 - If ft_strcpyto() ended on a closing quote, filter trailing characters
**		for anything other than whitespace and comments (using COMMENT_CHAR).
**		If not, call parse_comment_multi_ln() to parse a comment written on
**		multiple lines.
**
**	5 - Set S_COMM bit in fl->status to indicate that a valid comment was found.
*/

static int	parse_comment(t_asm_file *fl, char *ln, int fd)
{
	fl->ch = ft_strlen(COMM_CMD_STR);
	while (ln[fl->ch] && ln[fl->ch] != '"')
		if (!ft_iswhite(ln[fl->ch++]))
			return (exit_parsing(fl, E_COMM_OPEN));
	fl->ch++;
	ft_strcpyto(fl->hd.comment, ln + fl->ch, '"');
	if (ft_strlen(fl->hd.comment) > COMMENT_LENGTH)
		return (exit_parsing(fl, E_COMM_LEN));
	fl->ch += ft_strlen(fl->hd.comment);
	if (ln[fl->ch] == '"')
	{
		if (ln[++fl->ch])
			while (ln[fl->ch] && ln[fl->ch] != COMMENT_CHAR)
				if (!ft_iswhite(ln[fl->ch++]))
					return (exit_parsing(fl, E_COMM_EXTRA));
	}
	else
	{
		if (!parse_comment_multi_ln(fl, ln, fd))
			return (0);
	}
	fl->status |= S_COMM;
	return (1);
}

/*
**		int		parse_header(t_asm_file *fl, int fd);
**
**	Iterates with ft_gnl() through the file until both name and comm
**	commands, desginated by NAME_CMD_STR and COMM_CMD_STR respectively
**	have been found. Otherwise calls exit_parsing with error code and
**	leaves function.
*/

int			parse_header(t_asm_file *fl, int fd)
{
	char	*ln;

	ln = NULL;
	while (ft_gnl(fd, &ln) > 0)
	{
		if (ln[0] == '.')
		{
			if (!ft_strncmp(ln, NAME_CMD_STR, ft_strlen(NAME_CMD_STR)))
				parse_name(fl, ln, fd);
			else if (!ft_strncmp(ln, COMM_CMD_STR, ft_strlen(COMM_CMD_STR)))
				parse_comment(fl, ln, fd);
			else
				return (exit_parsing(fl, E_HEAD_CMD));
		}
		else if (ln[0] && ln[0] != COMMENT_CHAR)
			return (exit_parsing(fl, E_HEAD_MISS));
		ft_strdel(&ln);
		if (fl->exit || fl->status == (S_NAME | S_COMM))
			return (fl->exit ? 0 : 1);
		fl->ln++;
	}
	return (fl->status == (S_NAME | S_COMM) ? 1 : exit_parsing(fl, E_EMPTY));
}
