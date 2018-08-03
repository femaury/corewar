/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 22:24:31 by femaury           #+#    #+#             */
/*   Updated: 2018/07/26 21:55:05 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

static int	parse_name(t_asm_file *fl, char *ln, int fd)
{
	fl->ch = ft_strlen(NAME_CMD_STR);
	while (ln[fl->ch] && ln[fl->ch] != '"')
		if (!ft_iswhite(ln[fl->ch++]))
			return (exit_parsing(fl, E_NAME_OPEN));
	fl->ch++;
	if (ft_strlen(ln) - fl->ch > PROG_NAME_LENGTH)
		return (exit_parsing(fl, E_NAME_LEN));
	ft_strcpyto(fl->hd.prog_name, ln + fl->ch, '"');
	fl->ch += ft_strlen(fl->hd.prog_name);
	if (ln[fl->ch] == '"')
	{
		if (ln[++fl->ch])
			while (ln[fl->ch] && ln[fl->ch] != COMMENT_CHAR)
				if (!ft_iswhite(ln[fl->ch++]))
					return (exit_parsing(fl, E_NAME_EXTRA));
	}
	else
		if (!parse_name_multi_ln(fl, ln, fd))
			return (0);
	fl->status |= S_NAME;
	return (1);
}

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

static int	parse_comment(t_asm_file *fl, char *ln, int fd)
{
	fl->ch = ft_strlen(COMM_CMD_STR);
	while (ln[fl->ch] && ln[fl->ch] != '"')
		if (!ft_iswhite(ln[fl->ch++]))
			return (exit_parsing(fl, E_COMM_OPEN));
	fl->ch++;
	if (ft_strlen(ln) - fl->ch > COMMENT_LENGTH)
		return (exit_parsing(fl, E_COMM_LEN));
	ft_strcpyto(fl->hd.comment, ln + fl->ch, '"');
	fl->ch += ft_strlen(fl->hd.comment);
	if (ln[fl->ch] == '"')
	{
		if (ln[++fl->ch])
			while (ln[fl->ch] && ln[fl->ch] != COMMENT_CHAR)
				if (!ft_iswhite(ln[fl->ch++]))
					return (exit_parsing(fl, E_COMM_EXTRA));
	}
	else
		if (!parse_comment_multi_ln(fl, ln, fd))
			return (0);
	fl->status |= S_COMM;
	return (1);
}

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
		else if (ln[0])
			return (exit_parsing(fl, E_HEAD_MISS));
		ft_strdel(&ln);
		if (fl->exit || fl->status == (S_NAME | S_COMM))
			return (fl->exit ? 0 : 1);
		fl->ln++;
	}
	return (1);
}
