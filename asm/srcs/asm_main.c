/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:57:20 by femaury           #+#    #+#             */
/*   Updated: 2018/07/23 12:21:03 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			main(int ac, char **av)
{
	if (arg_parsing(ac, av))
	{
		ft_printf("Good argument(s).\n");
	}
	else
	{
		ft_printf("usage: ./asm file_name.s\n"
				"\tCan take multiple files.\n"
				"\tAll files need a .s extension.\n");
	}
	return (0);
}
