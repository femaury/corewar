/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:55:03 by femaury           #+#    #+#             */
/*   Updated: 2018/06/02 16:49:49 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE 42
# define STOP_CHAR '\n'

int		ft_gnl(const int fd, char **line);

#endif
