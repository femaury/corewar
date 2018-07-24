/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:35:34 by femaury           #+#    #+#             */
/*   Updated: 2018/07/24 17:54:27 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	exit_parsing(t_asm_file *fl, int err)
{
	if (err == E_OPEN)
		ft_printf("Error: Couldn't open file...\n");
	else if (err == E_HEAD_CMD || err == E_HEAD_LN)
	{
		ft_printf("Error at line %u, char %u: Invalid ", fl->ln, fl->ch);
		ft_printf(err == E_HEAD_LN ? "instruction...\n" : "command...\n");
	}
	fl->exit = 1;
	return (0);
}

static int	init_file(t_asm_file *fl)
{
	fl->tmp_ln = NULL;
	fl->ln = 0;
	fl->ch = 0;
	fl->multi_ln = 0;
	fl->exit = 0;
	fl->hd.magic = ft_revbits(COREWAR_EXEC_MAGIC);
	ft_bzero((void *)fl->hd.prog_name, PROG_NAME_LENGTH + 1);
	fl->hd.prog_size = 0;
	ft_bzero((void *)fl->hd.comment, COMMENT_LENGTH + 1);
}

static int	parse_name(t_asm_file *fl, char *line, int fd)
{
	fl->ch = ft_strlen(NAME_CMD_STR);
	if (ft_strncmp(line[fl->ch], " \"", 2))
		return (exit_parsing(fl, E_NAME_OPEN));
	fl->ch += 2;
	if (ft_strlen(line) - fl->ch > PROG_NAME_LENGTH)
		return (exit_parsing(fl, E_NAME_LEN));
	fl->hd.name = ft_strcpyto(fl->hd.name, line + fl->ch, '"');
	fl->ch += ft_strlen(fl->hd.name);
	if (line[fl->ch] && line[++fl->ch])
		return (exit_parsing(fl, E_NAME_EXTRA));
	if (!line[fl->ch])
	{
		fl->ch = 0;
		while (++fl->ln && ft_gnl(fd, &line) > 0 && !ft_strhasc(line, '"'))
		{
			ft_strdel(&line);
		}
	}
	fl->status |= S_NAME;
	return (1);
}

static int	parse_comment(t_asm_file *fl, char *line, int fd)
{
	fl->status |= S_COMM;
	return (1);
}

static int	parse_header(t_asm_file *fl, int fd)
{
	char	*line;

	line = NULL;
	while (ft_gnl(fd, &line) > 0)
	{
		if (line[0] == '.')
		{
			if (!ft_strncmp(line, NAME_CMD_STR, ft_strlen(NAME_CMD_STR)))
				parse_name(fl, fd, ln);
			else if (!ft_strncmp(line, COMM_CMD_STR, ft_strlen(COMM_CMD_STR)))
				parse_comment(fl, fd, ln);
			else
				return (exit_parsing(fl, E_HEAD_CMD));
		}
		else if (line[0])
			return (fl->tmp_ln = line);
		ft_strdel(&line);
		if (fl->exit || fl->status & (S_NAME | S_COMM))
			return (fl->exit ? 0 : 1);
		fl->ln++;
	}
	return (1);
}

int			parse_file(char *file)
{
	int			fd;
	t_asm_file	fl;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (exit_parsing(&fl, E_OPEN, -1, -1));
	init_file(&fl);
	if (!parse_header(&hd, fd, &ln))
		return (0);
	close(fd);
	return (1);
}
