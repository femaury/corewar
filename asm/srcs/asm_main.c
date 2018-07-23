/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:57:20 by femaury           #+#    #+#             */
/*   Updated: 2018/07/23 18:30:43 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac > 1)
	{
		while (++i < ac)
		{
			if (ft_stratcmp(av[i], "s", '.'))
				ft_printf("%s is valid.\n", av[i]);
			else
				ft_printf("%s is not valid.\n", av[i]);
		}
	}
	else
	{
		ft_printf("usage: ./asm file_name.s\n"
				"\tCan take multiple files.\n"
				"\tAll files need a .s extension.\n");
	}
	return (0);
}
