/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:35:34 by femaury           #+#    #+#             */
/*   Updated: 2018/07/24 20:17:28 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	exit_parsing(t_asm_file *fl, int er)
{
	if (er == E_OPEN)
		ft_printf("Error: Couldn't open file...\n");
	else if (er == E_HEAD_MISS)
		ft_printf("Error: %s is missing...\n",
				fl->status & S_NAME ? "comment" : "name");
	else
	{
		ft_printf("Error at line %u char %u: ", fl->ln, fl->ch);
		if (er == E_HEAD_CMD)
			ft_printf("Invalid command...");
		else if (er == E_NAME_OPEN || er == E_COMM_OPEN)
			ft_printf("%s command takes -> \"STRING\" as argument...\n",
					er == E_NAME_OPEN ? ".name" : ".comment");
		else if (er == E_NAME_LEN || er == E_COMM_LEN)
			ft_printf("%s is too long...\n", er == E_NAME_LEN ? "name" : "comment");
		else if (er == E_NAME_EXTRA || er == E_COMM_EXTRA)
			ft_printf("%s has trailing characters after closing double quote...\n",
					er == E_NAME_EXTRA ? "name" : "comment");
	}
	fl->exit = 1;
	return (0);
}

static void	init_file(t_asm_file *fl)
{
	fl->tmp_ln = NULL;
	fl->ln = 0;
	fl->ch = 0;
	fl->status = 0;
	fl->multi_ln = 0;
	fl->exit = 0;
	fl->hd.magic = ft_revbits(COREWAR_EXEC_MAGIC);
	ft_bzero((void *)fl->hd.prog_name, PROG_NAME_LENGTH + 1);
	fl->hd.prog_size = 0;
	ft_bzero((void *)fl->hd.comment, COMMENT_LENGTH + 1);
}

static int	parse_name(t_asm_file *fl, char *ln, int fd)
{
	fl->ch = ft_strlen(NAME_CMD_STR);
	if (ft_strncmp(&ln[fl->ch], " \"", 2))
		return (exit_parsing(fl, E_NAME_OPEN));
	fl->ch += 2;
	if (ft_strlen(ln) - fl->ch > PROG_NAME_LENGTH)
		return (exit_parsing(fl, E_NAME_LEN));
	ft_strcpyto(fl->hd.prog_name, ln + fl->ch, '"');
	fl->ch += ft_strlen(fl->hd.prog_name);
	if (ln[fl->ch] && ln[fl->ch + 1])
		return (exit_parsing(fl, E_NAME_EXTRA));
	if (!ln[fl->ch])
	{
		while (++fl->ln && ft_gnl(fd, &ln) > 0 && !ft_strhasc(ln, '"'))
		{
			if (ft_strlen(ln) + ft_strlen(fl->hd.prog_name) > PROG_NAME_LENGTH)
				return (exit_parsing(fl, E_NAME_LEN));
			ft_strcat(fl->hd.prog_name, ln);
			ft_strdel(&ln);
		}
		if (ft_strhasc(ln, '"') && *(ft_strchr(ln, '"') + 1))
			return (exit_parsing(fl, E_NAME_EXTRA));
		ft_strcatto(fl->hd.prog_name, ln, '"');
	}
	fl->status |= S_NAME;
	return (1);
}

static int	parse_comment(t_asm_file *fl, char *ln, int fd)
{
	fl->ch = ft_strlen(COMM_CMD_STR);
	if (ft_strncmp(&ln[fl->ch], " \"", 2))
		return (exit_parsing(fl, E_COMM_OPEN));
	fl->ch += 2;
	if (ft_strlen(ln) - fl->ch > COMMENT_LENGTH)
		return (exit_parsing(fl, E_COMM_LEN));
	ft_strcpyto(fl->hd.comment, ln + fl->ch, '"');
	fl->ch += ft_strlen(fl->hd.comment);
	if (ln[fl->ch] && ln[fl->ch + 1])
		return (exit_parsing(fl, E_COMM_EXTRA));
	if (!ln[fl->ch])
	{
		while (++fl->ln && ft_gnl(fd, &ln) > 0 && !ft_strhasc(ln, '"'))
		{
			if (ft_strlen(ln) + ft_strlen(fl->hd.comment) > COMMENT_LENGTH)
				return (exit_parsing(fl, E_COMM_LEN));
			ft_strcat(fl->hd.comment, ln);
			ft_strdel(&ln);
		}
		if (ft_strhasc(ln, '"') && *(ft_strchr(ln, '"') + 1))
			return (exit_parsing(fl, E_COMM_EXTRA));
		ft_strcatto(fl->hd.comment, ln, '"');
	}
	fl->status |= S_COMM;
	return (1);
}

static int	parse_header(t_asm_file *fl, int fd)
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

int			parse_file(char *file)
{
	int			fd;
	t_asm_file	fl;

	init_file(&fl);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (exit_parsing(&fl, E_OPEN));
	if (!parse_header(&fl, fd))
		return (0);
	ft_printf("Header successfully parsed!\n");
	ft_printf("name: %s\ncomment: %s\n", fl.hd.prog_name, fl.hd.comment);
	close(fd);
	return (1);
}
