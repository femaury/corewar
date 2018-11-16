/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:35:34 by femaury           #+#    #+#             */
/*   Updated: 2018/11/12 15:57:59 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	exit_parsing_ext(int er)
{
	if (er == E_BODY_BADOP)
		ft_dprintf(2, "Invalid instruction.\n");
	else if (er == E_BODY_PARAM)
		ft_dprintf(2, "Instruction parameters are invalid.\n");
	else if (er == E_BODY_LB_NAME)
		ft_dprintf(2, "Invalid label name.\n");
	else if (er == E_BODY_LB_CALL)
		ft_dprintf(2, "Label given as parameter doesn't exist.\n");
	else if (er == E_NAME_LEN || er == E_COMM_LEN)
		ft_dprintf(2, "%s is too long...\n",
				er == E_NAME_LEN ? "name" : "comment");
	else if (er == E_NAME_EXTRA || er == E_COMM_EXTRA)
		ft_dprintf(2, "%s has trailing characters after closing double "
				"quote...\n", er == E_NAME_EXTRA ? "name" : "comment");
	else if (er == E_NAME_NOEND || er == E_COMM_NOEND)
		ft_dprintf(2, "%s doesn't have a closing quote...\n",
				er == E_NAME_NOEND ? "name" : "comment");
	return (0);
}

int			exit_parsing(t_asm_file *fl, int er)
{
	if ((fl->exit = 1) && er == E_OPEN)
		ft_dprintf(2, "{RED}ERROR{EOC}: Couldn't open file...\n");
	else if (er == E_HEAD_MISS)
		ft_dprintf(2, "{RED}ERROR{EOC}: %s is missing...\n",
				fl->status & S_NAME ? "comment" : "name");
	else if (er == E_MALLOC)
		ft_dprintf(2, "{RED}ERROR{EOC}: Not enough memory to allocate...\n");
	else if (er == E_CREATE)
		ft_dprintf(2, "{RED}ERROR{EOC}: Couldn't create .cor file...\n");
	else if (er == E_EMPTY)
		ft_dprintf(2, "{RED}ERROR{EOC}: File is incomplete...\n");
	else
	{
		ft_dprintf(2, "{RED}ERROR{EOC} [{YELLOW}%03u{EOC}:{YELLOW}%03u{EOC}]: ",
				fl->ln + 1, fl->ch);
		if (er == E_HEAD_CMD)
			ft_dprintf(2, "Invalid command...\n");
		else if (er == E_NAME_OPEN || er == E_COMM_OPEN)
			ft_dprintf(2, "%s command's argument isn't a string.\n",
					er == E_NAME_OPEN ? ".name" : ".comment");
		else
			exit_parsing_ext(er);
	}
	return (0);
}

static void	init_file(t_asm_file *fl)
{
	fl->tmp_ln = NULL;
	fl->ln = 1;
	fl->ch = 1;
	fl->status = 0;
	fl->exit = 0;
	fl->onull = 0;
	fl->hd.magic = ft_revbits(COREWAR_EXEC_MAGIC);
	ft_bzero((void *)fl->hd.prog_name, PROG_NAME_LENGTH + 1);
	fl->hd.prog_size = 0;
	ft_bzero((void *)fl->hd.comment, COMMENT_LENGTH + 1);
	fl->bd.op_size = 0;
	fl->bd.op = NULL;
	fl->bd.label = NULL;
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
	if (!check_labels(&fl, &fl.bd.op, &fl.bd.label))
		return (exit_parsing(&fl, E_BODY_LB_CALL));
	create_binary(&fl, file_name);
	close(fd);
	free_labels(&fl.bd.label);
	free_ops(&fl.bd.op);
	return (1);
}
