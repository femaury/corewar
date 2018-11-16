/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:49:58 by femaury           #+#    #+#             */
/*   Updated: 2018/11/12 15:57:48 by femaury          ###   ########.fr       */
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
# define E_CREATE				2
# define E_MALLOC				3
# define E_EMPTY				4
# define E_HEAD_MISS 			5
# define E_HEAD_CMD 			6
# define E_NAME_OPEN			7
# define E_NAME_LEN				8
# define E_NAME_EXTRA			9
# define E_NAME_NOEND			10
# define E_COMM_OPEN			11
# define E_COMM_LEN				12
# define E_COMM_EXTRA			13
# define E_COMM_NOEND			14
# define E_BODY_BADOP			15
# define E_BODY_PARAM			16
# define E_BODY_LB_NAME			17
# define E_BODY_LB_CALL			18

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
# define REG_CHAR				'r'
# define SEPAR_CHAR				','

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

typedef struct		s_op_tab
{
	char			*name;
	unsigned int	opcode;
	unsigned int	p_count;
	unsigned int	p_type[3];
	unsigned int	dir_size;
	unsigned int	carry;
	unsigned int	ocp;
}					t_op_tab;

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
	unsigned int	type;
	unsigned int	size;
	unsigned int	value;
}					t_param;

typedef struct		s_op
{
	unsigned int	size;
	unsigned int	line;
	t_op_tab		info;
	t_param			params[3];
	struct s_op		*next;
}					t_op;

typedef struct		s_label
{
	char			*s;
	unsigned int	size;
	struct s_label	*next;
}					t_label;

typedef struct		s_body
{
	unsigned int	op_size;
	t_op			*op;
	t_label			*label;
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
int					get_params(t_asm_file *fl, char **params,
						int count, t_op *op);
int					get_label(t_asm_file *fl, char *str);
int					find_operation(t_asm_file *fl, char *str, t_op *op);
int					exit_parsing(t_asm_file *fl, int er);
void				create_binary(t_asm_file *fl, char *file_name);

t_op				*new_op(void);
void				add_op(t_op **head, t_op *new);
int					size_op(t_op **head);
int					sizeto_op(t_op **head, t_op *ref);

t_label				*new_label(char *label, unsigned int size);
void				add_label(t_label **head, t_label *new);
int					get_label_size(t_label **head, char *label);
int					check_labels(t_asm_file *fl, t_op **ophd, t_label **labhd);

int					free_params(int ret, char **params, size_t size);
void				free_labels(t_label **lst);
void				free_ops(t_op **lst);

extern t_op_tab		g_op_tab[17];

#endif
