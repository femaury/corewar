/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:49:58 by femaury           #+#    #+#             */
/*   Updated: 2018/09/17 20:16:21 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

/*
**	----------------------------- SYSTEM LIBRARIES -----------------------------
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

/*
**	------------------------------- MY LIBRARIES -------------------------------
*/

# include "../../libft/incs/libft.h"

/*
**	--------------------------------- DEFINES ----------------------------------
*/

# define E_OPEN 				1
# define E_HEAD_MISS 			2
# define E_HEAD_CMD 			3
# define E_NAME_OPEN			4
# define E_NAME_LEN				5
# define E_NAME_EXTRA			6
# define E_NAME_NOEND			7
# define E_COMM_OPEN			8
# define E_COMM_LEN				9
# define E_COMM_EXTRA			10
# define E_COMM_NOEND			11
# define E_BODY_BADOP			12

# define S_NAME					(1 << 0)
# define S_COMM					(1 << 1)

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STR			".name"
# define COMM_CMD_STR			".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

typedef char		t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

/*
**	-------------------------------- STRUCTURES --------------------------------
*/

typedef struct s_op_tab
{
	char			*name;
	unsigned int	opcode;
	unsigned int	p_count;
	unsigned int	p_type[3];
	unsigned int	dir_size;
	unsigned int	carry;

}				t_op_tab;

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_param
{
	char			*label;
	unsigned int	size;
	unsigned int	value;
}					t_param;

typedef struct		s_op
{
	char			*label;
	unsigned int	size;
	unsigned int	code;
	unsigned int	cp;
	t_param			params[3];
	struct s_inst	*next;
}					t_op;

typedef struct		s_body
{
	unsigned int	inst_size;
	t_op			op;
}					t_body;

typedef struct		s_asm_file
{
	char			*tmp_ln;
	unsigned int	ln;
	unsigned int	ch;
	unsigned int	status;
	unsigned int	exit;
	unsigned int	onull;
	t_header		hd;
	t_body			bd;
}					t_asm_file;

/*
**	------------------------------- ASM FUNCTIONS ------------------------------
*/

int					parse_file(char *file_name);
int					parse_header(t_asm_file *fl, int fd);
int					parse_body(t_asm_file *fl, int fd);
int					exit_parsing(t_asm_file *fl, int er);
void				create_binary(t_asm_file *fl, char *file_name);

extern t_op_tab		g_op_tab[17];

#endif
