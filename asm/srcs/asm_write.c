/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 22:37:35 by femaury           #+#    #+#             */
/*   Updated: 2018/07/26 21:33:38 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*modify_name(char *file_name)
{
	char			*new;
	size_t			len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(file_name);
	if (!(new = (char *)malloc(len + 2)))
		return (NULL);
	new = ft_strcpy(new, file_name);
	new[len - 1] = 'c';
	new = ft_strcat(new, "or");
	return (new);
}

void	create_binary(t_asm_file *fl, char *file_name)
{
	int		fd;
	char	*name;

	if (!(name = modify_name(file_name)))
		return ;
	if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
		return ;
	write(fd, &fl->hd.magic, 4);
	write(fd, fl->hd.prog_name, PROG_NAME_LENGTH);
	write(fd, &fl->onull, 4);
	write(fd, &fl->onull, 4); /* Place Holder for Instruction Number */
	write(fd, fl->hd.comment, COMMENT_LENGTH);
	ft_printf("Writing output program to %s\n", name);
	close(fd);
}
