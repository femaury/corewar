/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:57:20 by femaury           #+#    #+#             */
/*   Updated: 2018/11/12 15:58:55 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	parse_flags(char *str)
{
	if (ft_strequ(str, "-h") || ft_strequ(str, "-H"))
	{
		ft_dprintf(1, "\t<-- {MAGENTA}Corewar's ASM{EOC} -->\n\n"
				"usage: ./asm file_name.s\n"
				"   {YELLOW}->{EOC}   Can take multiple files.\n"
				"   {YELLOW}->{EOC}   All files need a .s extension.\n\n"
				"file format:\n"
				"   {YELLOW}->{EOC}   .name \"name\"\n"
				"   {YELLOW}->{EOC}   .comment \"comment\"\n"
				"   {YELLOW}->{EOC}   \n"
				"   {YELLOW}->{EOC}   label: instruction\n\n"
				"instructions:\n"
				"   {YELLOW}->{EOC}   [live, ld, st, add, sub, and, or,"
				"xor, zjmp, ldi, sti, fork, lld, lldi, lfork, aff]\n\n");
		return (1);
	}
	return (0);
}

int			main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac > 1)
	{
		if (parse_flags(av[1]))
			i++;
		while (++i < ac)
		{
			if (ft_stratcmp(av[i], "s", '.'))
				parse_file(av[i]);
			else
				ft_dprintf(2, "{RED}ERROR{EOC}: %s is not an asm file.\n",
						av[i]);
		}
	}
	else
		ft_dprintf(2, "usage: ./asm [-h] file_name.s\n\n"
				"   {YELLOW}->{EOC}   Can take multiple files.\n"
				"   {YELLOW}->{EOC}   All files need a .s extension.\n");
	return (0);
}
