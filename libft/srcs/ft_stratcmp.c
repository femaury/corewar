/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stratcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:20:15 by femaury           #+#    #+#             */
/*   Updated: 2018/07/23 18:28:17 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stratcmp(const char *s, const char *ref, char mark)
{
	char	*cmp;

	if (!(cmp = ft_strrchr(s, mark)))
		return (0);
	if (ft_strcmp(cmp + 1, ref))
		return (0);
	return (1);
}
