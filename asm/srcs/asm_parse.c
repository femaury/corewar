/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:35:34 by femaury           #+#    #+#             */
/*   Updated: 2018/07/24 22:34:01 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			exit_parsing(t_asm_file *fl, int er)
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
			ft_printf("%s is too long...\n",
					er == E_NAME_LEN ? "name" : "comment");
		else if (er == E_NAME_EXTRA || er == E_COMM_EXTRA)
			ft_printf("%s has trailing characters after closing double "
					"quote...\n", er == E_NAME_EXTRA ? "name" : "comment");
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
	fl->exit = 0;
	fl->hd.magic = ft_revbits(COREWAR_EXEC_MAGIC);
	ft_bzero((void *)fl->hd.prog_name, PROG_NAME_LENGTH + 1);
	fl->hd.prog_size = 0;
	ft_bzero((void *)fl->hd.comment, COMMENT_LENGTH + 1);
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
	ft_printf("name: %s\ncomment: %s\n\n", fl.hd.prog_name, fl.hd.comment);
	close(fd);
	return (1);
}
