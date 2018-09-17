/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:35:34 by femaury           #+#    #+#             */
/*   Updated: 2018/09/17 20:32:28 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	exit_parsing_ext(t_asm_file *fl, int er)
{
	(void)fl;
	(void)er;
	return (0);
}

int			exit_parsing(t_asm_file *fl, int er)
{
	if ((fl->exit = 1) && er == E_OPEN)
		ft_printf("ERROR: Couldn't open file...\n");
	else if (er == E_HEAD_MISS)
		ft_printf("ERROR: %s is missing...\n",
				fl->status & S_NAME ? "comment" : "name");
	else
	{
		ft_printf("ERROR [%03u:%03u]: ", fl->ln + 1, fl->ch);
		if (er == E_HEAD_CMD)
			ft_printf("Invalid command...\n");
		else if (er == E_NAME_OPEN || er == E_COMM_OPEN)
			ft_printf("%s command's argument isn't a string.\n",
					er == E_NAME_OPEN ? ".name" : ".comment");
		else if (er == E_NAME_LEN || er == E_COMM_LEN)
			ft_printf("%s is too long...\n",
					er == E_NAME_LEN ? "name" : "comment");
		else if (er == E_NAME_EXTRA || er == E_COMM_EXTRA)
			ft_printf("%s has trailing characters after closing double "
					"quote...\n", er == E_NAME_EXTRA ? "name" : "comment");
		else if (er == E_NAME_NOEND || er == E_COMM_NOEND)
			ft_printf("%s doesn't have a closing quote...\n",
					er == E_NAME_NOEND ? "name" : "comment");
		else
			exit_parsing_ext(fl, er);
	}
	return (0);
}

static void	init_file(t_asm_file *fl)
{
	fl->tmp_ln = NULL;
	fl->ln = 0;
	fl->ch = 0;
	fl->status = 0;
	fl->exit = 0;
	fl->onull = 0;
	fl->hd.magic = ft_revbits(COREWAR_EXEC_MAGIC);
	ft_bzero((void *)fl->hd.prog_name, PROG_NAME_LENGTH + 1);
	fl->hd.prog_size = 0;
	ft_bzero((void *)fl->hd.comment, COMMENT_LENGTH + 1);
}

int			parse_file(char *file_name)
{
	int			fd;
	t_asm_file	fl;

	init_file(&fl);
	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (exit_parsing(&fl, E_OPEN));
	if (!parse_header(&fl, fd))
		return (0);
	if (!parse_body(&fl, fd))
		return (0);
	create_binary(&fl, file_name);
	close(fd);
	return (1);
}
