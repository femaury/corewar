/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:02:11 by femaury           #+#    #+#             */
/*   Updated: 2018/06/19 14:56:07 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"

static int	ft_readline(const int fd, t_list *curr)
{
	char	buff[BUFF_SIZE + 1];
	int		rd;

	if (read(fd, buff, 0) == -1)
		return (-1);
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rd] = '\0';
		curr->content = ft_strjoin(curr->content, buff);
		ft_memdel(&curr->content_ptr);
		curr->content_ptr = curr->content;
		if (ft_strchr(buff, STOP_CHAR))
			break ;
	}
	return (rd);
}

static int	ft_copyline(t_list *curr, char **line)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (*(char *)(curr->content))
	{
		while (*(char *)(curr->content + i) != STOP_CHAR
				&& *(char *)(curr->content + i))
			i++;
		if (!(*line = (char *)ft_memalloc(i + 1)))
			return (-1);
		while (j < i)
		{
			*(*line + j) = *(char *)(curr->content + j);
			j++;
		}
		*(*line + i) = '\0';
		curr->content += *(char *)(curr->content + i) ? i + 1 : i;
		return (1);
	}
	return (0);
}

int			ft_gnl(const int fd, char **line)
{
	static t_list	*files;
	t_list			*curr;
	int				rd;

	if (fd < 0 || !line)
		return (-1);
	if (!(curr = ft_lstfind_size(files, fd)))
	{
		if (!(curr = ft_lstnew("\0", 1)))
			return (-1);
		curr->content_size = fd;
		ft_lstprepend(&files, curr);
	}
	if ((rd = ft_readline(fd, curr)) < 0)
		return (rd);
	return (ft_copyline(curr, line));
}
