/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_get_wstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 20:53:38 by femaury           #+#    #+#             */
/*   Updated: 2018/05/23 12:22:52 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_get_wc(t_buffer *buff, size_t bytes, wchar_t wc)
{
	static char	str[4];

	if (bytes == 1)
		str[0] = wc;
	else
	{
		if (bytes == 2)
			str[0] = (wc >> 6) | 0xC0;
		else
		{
			if (bytes == 3)
				str[0] = (wc >> 12) | 0xE0;
			else
			{
				str[0] = (wc >> 18) | 0xF0;
				str[1] = ((wc >> 12) & 0x3F) | 0x80;
			}
			str[bytes - 2] = ((wc >> 6) & 0x3F) | 0x80;
		}
		str[bytes - 1] = (wc & 0x3F) | 0x80;
	}
	ftp_fill_buffer(buff, str, bytes);
}

static void		ft_format_wc(t_buffer *buff, wchar_t wc, size_t bytes,
		t_format fstr)
{
	if (WIDTH > 1)
	{
		if (FLAGS & F_MINUS)
		{
			ft_get_wc(buff, bytes, wc);
			ftp_pad_buffer(buff, ' ', WIDTH - bytes);
		}
		else
		{
			ftp_pad_buffer(buff, ' ', WIDTH - bytes);
			ft_get_wc(buff, bytes, wc);
		}
	}
	else
		ft_get_wc(buff, bytes, wc);
}

static void		ft_get_ws(t_buffer *buff, wchar_t *ws, int strlen)
{
	int	clen;

	clen = 0;
	while (*ws && (strlen -= clen) > 0)
	{
		clen = ft_wcharlen(*ws);
		if (strlen - clen < 0)
			clen += (strlen - clen);
		ft_get_wc(buff, clen, *ws++);
	}
}

static void		ft_format_ws(t_buffer *buff, wchar_t *ws, size_t strlen,
		t_format fstr)
{
	if (!ftp_check_wstr(buff, ws))
		return ;
	strlen = (fstr.hasprec && PREC < strlen ? PREC : strlen);
	if (WIDTH > strlen)
	{
		if (FLAGS & F_MINUS)
		{
			ft_get_ws(buff, ws, strlen);
			ftp_pad_buffer(buff, ' ', WIDTH - strlen);
		}
		else
		{
			ftp_pad_buffer(buff, ' ', WIDTH - strlen);
			ft_get_ws(buff, ws, strlen);
		}
	}
	else
		ft_get_ws(buff, ws, strlen);
}

void			ftp_get_wstr(t_buffer *buff, va_list args, t_format fstr)
{
	wchar_t			*ws;
	unsigned int	wc;

	if (TYPE == 'C' || TYPE == 'c')
	{
		wc = va_arg(args, wchar_t);
		if (wc > 0x10FFFF || (wc >= 0xD800 && wc <= 0xDFFF))
			buff->error |= 1;
		else
			ft_format_wc(buff, wc, ft_wcharlen(wc), fstr);
	}
	else if (TYPE == 'S' || TYPE == 's')
	{
		if (!(ws = va_arg(args, wchar_t *)))
			ftp_fill_buffer(buff, "(null)", 6);
		else if (!(fstr.hasprec && !PREC && !WIDTH))
			ft_format_ws(buff, ws, ft_wstrlen(ws), fstr);
	}
}
