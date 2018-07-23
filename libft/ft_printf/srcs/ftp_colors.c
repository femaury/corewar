/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 09:38:28 by femaury           #+#    #+#             */
/*   Updated: 2018/05/23 11:28:43 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ftp_colors(char *format, t_buffer *buff, int *pos, int *start)
{
	unsigned int	printed;

	printed = 0;
	if (ft_strnequ(format + *pos, "{RED}", 5))
		ftp_fill_buffer(buff, "\033[31m", (printed = 5));
	else if (ft_strnequ(format + *pos, "{GREEN}", 7))
		ftp_fill_buffer(buff, "\033[32m", (printed = 7) - 2);
	else if (ft_strnequ(format + *pos, "{YELLOW}", 8))
		ftp_fill_buffer(buff, "\033[33m", (printed = 8) - 3);
	else if (ft_strnequ(format + *pos, "{BLUE}", 6))
		ftp_fill_buffer(buff, "\033[34m", (printed = 6) - 1);
	else if (ft_strnequ(format + *pos, "{MAGENTA}", 9))
		ftp_fill_buffer(buff, "\033[35m", (printed = 9) - 4);
	else if (ft_strnequ(format + *pos, "{CYAN}", 6))
		ftp_fill_buffer(buff, "\033[36m", (printed = 6) - 1);
	else if (ft_strnequ(format + *pos, "{EOC}", 5))
		ftp_fill_buffer(buff, "\033[0m", (printed = 5) - 1);
	*pos += printed;
	if (printed)
		*start = *pos;
	else
		*pos += 1;
}
