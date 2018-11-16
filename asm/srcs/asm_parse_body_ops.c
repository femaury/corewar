/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_body_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:40:56 by femaury           #+#    #+#             */
/*   Updated: 2018/11/12 17:52:43 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**		int		set_dir(t_asm_file *fl, char *str, t_op *op, unsigned i);
**
**	Parses a DIRECT parameter. Checks that the instruction can contain a DIR,
**	that the param starts with DIRECT_CHAR. Then it checks whether it is
**	followed by a label or a numeric value. For the former, it makes sure it
**	is a valid label (**not in the sense that it exists, but that its name
**	is valid**) and then adds to the t_param structure all relevant information.
**	For the latter, it makes sure it is a valid numeric value ([-]N) and also
**	adds to t_param relevant info. Adds +1 to status to indicate a valid param
**	was parsed.
*/

static int	set_dir(t_asm_file *fl, char *str, t_op *op, unsigned i)
{
	if ((op->info.p_type[i] & T_DIR) && str[0] == DIRECT_CHAR)
	{
		op->params[i].type = T_DIR;
		if (str[1] == LABEL_CHAR && ft_strisonly(str + 2, LABEL_CHARS))
		{
			if (!(op->params[i].label = ft_memalloc(ft_strlen(str + 2) + 1)))
				return (exit_parsing(fl, E_MALLOC));
			op->params[i].label = ft_strcpyto(op->params[i].label,
					str + 2, SEPAR_CHAR);
			op->params[i].size = op->info.dir_size;
			fl->status++;
		}
		else if (ft_strisonly(str + (str[1] == '-' ? 2 : 1), "0123456789"))
		{
			op->params[i].value = ft_atoi(str + 1);
			op->params[i].size = op->info.dir_size;
			fl->status++;
		}
	}
	return (1);
}

/*
**		int	set_ind(t_asm_file *fl, char *str, t_param *param, unsigned type);
**
**	Parses an INDIRECT parameter. Same as set_dir() above.
*/

static int	set_ind(t_asm_file *fl, char *str, t_param *param, unsigned type)
{
	if (type & T_IND)
	{
		if (str[0] == LABEL_CHAR)
		{
			if (!(param->label = ft_memalloc(ft_strlen(str + 1))))
				return (exit_parsing(fl, E_MALLOC));
			param->label = ft_strcpyto(param->label, str + 1, SEPAR_CHAR);
			param->size = 2;
			param->type = T_IND;
			fl->status++;
		}
		else if (ft_strisonly(str + (str[0] == '-' ? 1 : 0), "0123456789"))
		{
			param->value = ft_atoi(str);
			param->size = 2;
			param->type = T_IND;
			fl->status++;
		}
	}
	return (1);
}

/*
**		int	set_reg(t_asm_file *fl, char *str, t_param *param, unsigned type);
**
**	Parses a REGISTER parameter. Checks that the instruction can contain a REG,
**	that the param starts with a REG_CHAR and that the numeric value given is
**	valid (<= REG_NUMBER). Adds all relevant information to t_param. Adds +1 to
**	status to indicate a valid param was parsed.
*/

static int	set_reg(t_asm_file *fl, char *str, t_param *param, unsigned type)
{
	if ((type & T_REG) && str[0] == REG_CHAR)
	{
		if (ft_strisonly(str + 1, "0123456789")
				&& ft_atoi(str + 1) <= REG_NUMBER && ft_atoi(str + 1) > 0)
		{
			param->type = T_REG;
			param->value = ft_atoi(str + 1);
			param->size = 1;
			fl->status++;
		}
	}
	return (1);
}

/*
**		int	set_params(t_asm_file *fl, char **params, t_op *op, unsigned nb);
**
**	Calls the proper parsing function for all params found in (char **)params.
**	Checks that the right number of params, through fl->status, has been parsed.
**	Then calculates the size of the instruction.
*/

static int	set_params(t_asm_file *fl, char **params, t_op *op, unsigned nb)
{
	unsigned int	i;

	i = 0;
	while (params[i])
	{
		if (!set_dir(fl, params[i], op, i))
			return (0);
		if (!set_ind(fl, params[i], &op->params[i], op->info.p_type[i]))
			return (0);
		set_reg(fl, params[i], &op->params[i], op->info.p_type[i]);
		i++;
	}
	if (fl->status != nb)
		return (exit_parsing(fl, E_BODY_PARAM));
	op->size = op->params[0].size + op->params[1].size + op->params[2].size
		+ (op->info.ocp ? 2 : 1);
	return (1);
}

/*
**		int		get_params(t_asm_file *fl, char **params, int count, t_op *op);
**
**	Checks whether the instructions requires 1, 2 or 3 parameters and that
**	there are enough parameters in (char **)params, then calls the appropriate
**	functions to parse them.
*/

int			get_params(t_asm_file *fl, char **params, int count, t_op *op)
{
	if (!params)
		return (exit_parsing(fl, E_MALLOC));
	if (op->info.p_count == 1 && ft_strtabsize(params) == 1 && !count)
	{
		if (!set_dir(fl, params[0], op, 0))
			return (free_params(0, params, 1));
		set_reg(fl, params[0], &op->params[0], op->info.p_type[0]);
		op->size = op->params[0].size + (op->info.ocp ? 2 : 1);
		if (fl->status == 1)
			return (free_params(1, params, 1));
	}
	else if (op->info.p_count == 2 && ft_strtabsize(params) == 2 && count == 1)
	{
		if (!set_params(fl, params, op, 2) || fl->status != 2)
			return (free_params(0, params, 2));
		return (free_params(1, params, 2));
	}
	else if (ft_strtabsize(params) == 3 && count == 2)
	{
		if (!set_params(fl, params, op, 3) || fl->status != 3)
			return (free_params(0, params, 3));
		return (free_params(1, params, 3));
	}
	return (exit_parsing(fl, E_BODY_PARAM));
}
