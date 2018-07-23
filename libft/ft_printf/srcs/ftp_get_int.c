/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:20:21 by femaury           #+#    #+#             */
/*   Updated: 2018/05/23 09:30:21 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_set_extra(char *nb, t_format fstr, size_t len)
{
	int		extra;

	if (TYPE == '%')
		return (0);
	if ((FLAGS & (F_PLUS | F_SPACE | F_HASH)) || nb[0] == '-')
	{
		extra = 1;
		if (TYPE == 'p')
			return (2);
		if ((FLAGS & F_HASH) && nb[0] == '0')
			return (0);
		if ((FLAGS & F_HASH) && TYPE != 'o' && TYPE != 'O')
			extra = 2;
		if (fstr.hasprec && PREC <= len && extra == 1 && WIDTH <= len)
			return (0);
		return (PREC > WIDTH && TYPE != 'o' && TYPE != 'O' ? (0) : (extra));
	}
	return (0);
}

static void	ft_prepend(t_buffer *buff, char *nb, size_t len, t_format fstr)
{
	if (((FLAGS & (F_PLUS | F_SPACE | F_HASH)) || nb[0] == '-') && TYPE != '%')
	{
		if (nb[0] == '-')
			ftp_pad_buffer(buff, '-', 1);
		else if (FLAGS & F_HASH)
		{
			if (nb[0] != '0' && nb[0])
			{
				if (TYPE == 'o' || TYPE == 'O')
					ftp_pad_buffer(buff, '0', 1);
				else
					ftp_fill_buffer(buff, (TYPE == 'X' ? "0X" : "0x"), 2);
			}
			else if ((TYPE == 'o' || TYPE == 'O') && fstr.hasprec && !PREC)
				ftp_pad_buffer(buff, '0', 1);
			else if (TYPE == 'p')
				ftp_fill_buffer(buff, "0x", 2);
		}
		else if (!(fstr.hasprec && PREC <= len) && !ft_strhasc("oOxX", TYPE))
			ftp_pad_buffer(buff, ((FLAGS & F_PLUS) ? '+' : ' '), 1);
		else if (TYPE == 'i' || TYPE == 'd' || TYPE == 'D')
			ftp_pad_buffer(buff, ((FLAGS & F_PLUS) ? '+' : ' '), 1);
	}
}

static void	ft_extend2(t_buffer *buff, char *nb, size_t len, t_format fstr)
{
	int		extra;

	extra = ft_set_extra(nb, fstr, len);
	if ((FLAGS & F_ZERO) || fstr.hasprec)
	{
		if (fstr.hasprec && PREC < WIDTH - (WIDTH ? extra : 0))
			ftp_pad_buffer(buff, ' ',
					WIDTH - (PREC > len ? PREC : len) - extra);
		ft_prepend(buff, nb, len, fstr);
		if (fstr.hasprec && extra && ft_strhasc("oO", TYPE))
			ftp_pad_buffer(buff, '0',
					PREC - (PREC > len + extra ? len + extra : PREC));
		else if (fstr.hasprec)
			ftp_pad_buffer(buff, '0', PREC - (PREC > len ? len : PREC));
		else if (WIDTH >= len + extra)
			ftp_pad_buffer(buff, '0', WIDTH - len - extra);
		ftp_fill_buffer(buff, nb + (nb[0] == '-' ? 1 : 0), len);
	}
	else
	{
		ftp_pad_buffer(buff, ' ', WIDTH - len - extra);
		ft_prepend(buff, nb, len, fstr);
		ftp_fill_buffer(buff, nb + (nb[0] == '-' ? 1 : 0), len);
	}
}

static void	ft_extend(t_buffer *buff, char *nb, size_t len, t_format fstr)
{
	int		extra;

	extra = ft_set_extra(nb, fstr, len);
	if (WIDTH > len || PREC > len)
	{
		if (FLAGS & F_MINUS)
		{
			ft_prepend(buff, nb, len, fstr);
			if (PREC > len)
				ftp_pad_buffer(buff, '0', PREC - len);
			ftp_fill_buffer(buff, nb + (nb[0] == '-' ? 1 : 0), len);
			if (PREC > len && WIDTH > PREC)
				ftp_pad_buffer(buff, ' ', WIDTH - PREC - extra);
			else if (WIDTH > PREC)
				ftp_pad_buffer(buff, ' ', WIDTH - len - extra);
		}
		else
			ft_extend2(buff, nb, len, fstr);
	}
	else
	{
		ft_prepend(buff, nb, len, fstr);
		ftp_fill_buffer(buff, nb + (nb[0] == '-' ? 1 : 0), len);
	}
}

void		ftp_get_int(t_buffer *buff, char *nb, t_format fstr)
{
	if (TYPE == 'p')
	{
		FLAGS |= F_HASH;
		ft_setlowcase(nb);
	}
	else if (TYPE == 'x')
		ft_setlowcase(nb);
	else if (TYPE == '%')
		PREC = 0;
	ft_extend(buff, nb, ft_strlen(nb) - (nb[0] == '-' ? 1 : 0), fstr);
}
