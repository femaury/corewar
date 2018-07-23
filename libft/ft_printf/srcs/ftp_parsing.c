/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 18:12:12 by femaury           #+#    #+#             */
/*   Updated: 2018/05/23 09:36:33 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_parsing_flags(char *format, t_format *fstr, int *pos)
{
	while (format[*pos] == '-' || format[*pos] == '+' || format[*pos] == ' ' ||
			format[*pos] == '0' || format[*pos] == '#')
	{
		if (format[*pos] == ' ')
			fstr->flags |= F_SPACE;
		else if (format[*pos] == '#')
			fstr->flags |= F_HASH;
		else if (format[*pos] == '+')
			fstr->flags |= F_PLUS;
		else if (format[*pos] == '-')
			fstr->flags |= F_MINUS;
		else if (format[*pos] == '0')
			fstr->flags |= F_ZERO;
		*pos += 1;
	}
}

static void	ft_parsing_lenflags(char *format, t_format *fstr, int *pos)
{
	if (format[*pos] == 'h' && format[*pos + 1] == 'h')
	{
		*pos += 1;
		fstr->lflags |= LF_CTOI;
	}
	else if (format[*pos] == 'h')
		fstr->lflags |= LF_SHTOI;
	else if (format[*pos] == 'l' && format[*pos + 1] == 'l')
	{
		*pos += 1;
		fstr->lflags |= LF_LLONG;
	}
	else if (format[*pos] == 'l')
		fstr->lflags |= LF_LONG;
	else if (format[*pos] == 'j')
		fstr->lflags |= LF_IMAX;
	else if (format[*pos] == 'z')
		fstr->lflags |= LF_SIZE;
	if (format[*pos] == 'h' || format[*pos] == 'l' || format[*pos] == 'j' ||
			format[*pos] == 'z')
		*pos += 1;
}

static void	ft_parsing_digits(char *format, t_format *fstr, int *pos)
{
	if (ft_isdigit(format[*pos]))
		fstr->width = ft_atoi(format + *pos);
	while (ft_isdigit(format[*pos]))
		*pos += 1;
	if (format[*pos] == '.')
	{
		*pos += 1;
		fstr->hasprec = 1;
		fstr->prec = ft_atoi(format + *pos);
	}
	while (ft_isdigit(format[*pos]))
		*pos += 1;
}

void		ftp_parsing(char *format, t_buffer *buff, va_list args, int *pos)
{
	t_format	fstr;

	if (format[*pos] && format[*pos] != '%')
	{
		fstr.flags = 0;
		fstr.lflags = 0;
		fstr.width = 0;
		fstr.hasprec = 0;
		fstr.prec = 0;
		fstr.type = 0;
		ft_parsing_flags(format, &fstr, pos);
		ft_parsing_digits(format, &fstr, pos);
		ft_parsing_lenflags(format, &fstr, pos);
		if (!format[*pos])
			return ;
		if (ft_strhasc("sSpdDioOuUxXcCb%", format[*pos]))
		{
			fstr.type = format[*pos];
			*pos += 1;
			ftp_get_arg(buff, args, fstr);
		}
	}
	else if (format[*pos] == '%')
		*pos += 1;
}
