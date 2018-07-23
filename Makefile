# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: femaury <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 20:03:09 by femaury           #+#    #+#              #
#    Updated: 2018/07/23 11:13:48 by femaury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =
SRC_PATH = srcs
SRC_NAME = 
OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_PATH = incs
INC_NAME = 
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))
LIB = libft/libft.a libft/ft_printf/libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_PATH)

T = $(words $(SRC_NAME))
N = x
C = $(words $N)$(eval N := x $N)
ECHO = echo "\r[\033[33m`expr $C '*' 100 / $T`%\033[0m] \
	   Compiling \033[35m$(NAME)\033[0m...\c"

.PHONY: all, clean, fclean, re

all:
	@$(MAKE) -C libft/
	@$(MAKE) -C asm/
	@$(MAKE) -C corewar/

clean:
ifeq ($(MAKECMDGOALS), clean)
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C asm/ clean
	@$(MAKE) -C corewar/ clean
endif

fclean: clean
	@$(MAKE) -C libft/ fclean
	@$(MAKE) -C asm/ fclean
	@$(MAKE) -C corewar/ fclean
ifeq ($(MAKECMDGOALS), re)
	@echo ""
endif

re: fclean all
