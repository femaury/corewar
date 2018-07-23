/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_arg_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:19:50 by femaury           #+#    #+#             */
/*   Updated: 2018/07/23 12:20:29 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	file_ext(char *av)
{
	int		i;
	char	*cmp;

	i = 0;
	if (!(cmp = ft_strrchr(av, '.')))
		return (0);
	if (ft_strcmp(cmp, ".s"))
		return (0);
	return (1);
}

int			arg_parsing(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac == 1)
		return (0);
	while (++i < ac)
		if (!file_ext(av[i]))
			return (0);
	return (1);
}
