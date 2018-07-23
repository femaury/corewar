/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:46:54 by femaury           #+#    #+#             */
/*   Updated: 2018/05/23 09:30:09 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_set_base(t_format fstr)
{
	if (TYPE == 'b')
		return (2);
	if (TYPE == 'x' || TYPE == 'X' || TYPE == 'p')
		return (16);
	if (TYPE == 'o' || TYPE == 'O')
		return (8);
	return (10);
}

static void	ft_get_unsigned(t_buffer *buff, va_list args, t_format fstr)
{
	uintmax_t	nb;

	FLAGS &= (~F_PLUS & ~F_SPACE);
	if (TYPE == '%')
		ftp_get_int(buff, "%", fstr);
	else
	{
		if ((LFLAGS & (LF_LONG | LF_LLONG)) || TYPE == 'U')
			nb = (uintmax_t)((LFLAGS & LF_LLONG) ? va_arg(args,
						unsigned long long) : va_arg(args, unsigned long));
		else if (LFLAGS & (LF_CTOI | LF_SHTOI))
			nb = (uintmax_t)((LFLAGS & LF_CTOI) ? (unsigned char)(va_arg(args,
							int)) : (unsigned short)(va_arg(args, int)));
		else if (LFLAGS & (LF_IMAX | LF_SIZE))
			nb = (uintmax_t)((LFLAGS & LF_IMAX) ? va_arg(args, uintmax_t)
					: va_arg(args, size_t));
		else if (TYPE == 'p')
			nb = (uintmax_t)(va_arg(args, void *));
		else
			nb = (uintmax_t)(va_arg(args, unsigned int));
		if (fstr.hasprec && PREC == 0 && ft_strhasc("uUxXoOp", TYPE) && nb == 0)
			ftp_get_int(buff, "", fstr);
		else
			ftp_get_int(buff, ftp_uimaxtoa_base(nb, ft_set_base(fstr)), fstr);
	}
}

void		ftp_get_arg(t_buffer *buff, va_list args, t_format fstr)
{
	intmax_t	nb;

	if (ft_strhasc("sScC", TYPE))
		ftp_get_str(buff, args, fstr);
	else if (TYPE == 'i' || TYPE == 'd' || TYPE == 'D')
	{
		if ((LFLAGS & (LF_LONG | LF_LLONG)) || TYPE == 'D')
			nb = (intmax_t)((LFLAGS & LF_LLONG) ? va_arg(args, long long)
					: va_arg(args, long));
		else if (LFLAGS & (LF_CTOI | LF_SHTOI))
			nb = (intmax_t)((LFLAGS & LF_CTOI) ? (char)(va_arg(args, int))
					: (short)(va_arg(args, int)));
		else if (LFLAGS & (LF_IMAX | LF_SIZE))
			nb = (intmax_t)((LFLAGS & LF_IMAX) ? va_arg(args, intmax_t)
					: va_arg(args, size_t));
		else
			nb = (intmax_t)(va_arg(args, int));
		if (fstr.hasprec && PREC == 0 && nb == 0)
			ftp_get_int(buff, "", fstr);
		else
			ftp_get_int(buff, ftp_imaxtoa_base(nb, 10), fstr);
	}
	else if (ft_strhasc("uUoOxXpb%", TYPE))
		ft_get_unsigned(buff, args, fstr);
}
