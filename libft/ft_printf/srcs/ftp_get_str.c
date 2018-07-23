/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 17:41:19 by femaury           #+#    #+#             */
/*   Updated: 2018/05/23 11:52:48 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_get_c(t_buffer *buff, va_list args, t_format fstr)
{
	char	c;

	c = (unsigned char)va_arg(args, int);
	if (WIDTH > 1)
	{
		if (FLAGS & F_MINUS)
		{
			ftp_pad_buffer(buff, c, 1);
			ftp_pad_buffer(buff, ' ', WIDTH - 1);
		}
		else
		{
			ftp_pad_buffer(buff, ' ', WIDTH - 1);
			ftp_pad_buffer(buff, c, 1);
		}
	}
	else
		ftp_pad_buffer(buff, c, 1);
}

static void	ft_get_s(t_buffer *buff, char *str, t_format fstr)
{
	size_t	strlen;

	if (fstr.hasprec && !PREC && !WIDTH)
		return ;
	strlen = ft_strlen(str);
	strlen = (fstr.hasprec && PREC < strlen ? PREC : strlen);
	if (WIDTH > strlen)
	{
		if (FLAGS & F_MINUS)
		{
			ftp_fill_buffer(buff, str, strlen);
			ftp_pad_buffer(buff, ' ', WIDTH - strlen);
		}
		else
		{
			ftp_pad_buffer(buff, ' ', WIDTH - strlen);
			ftp_fill_buffer(buff, str, strlen);
		}
	}
	else
		ftp_fill_buffer(buff, str, strlen);
}

void		ftp_get_str(t_buffer *buff, va_list args, t_format fstr)
{
	char	*str;

	if (TYPE == 'c' && !(LFLAGS & LF_LONG))
		ft_get_c(buff, args, fstr);
	else if (TYPE == 's' && !(LFLAGS & LF_LONG))
	{
		if (!(str = va_arg(args, char *)))
			ft_get_s(buff, "(null)", fstr);
		else
			ft_get_s(buff, str, fstr);
	}
	else if (TYPE == 'C' || TYPE == 'S' ||
			(ft_strhasc("cs", TYPE) && (LFLAGS & LF_LONG)))
		ftp_get_wstr(buff, args, fstr);
}
