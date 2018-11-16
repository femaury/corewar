# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: femaury <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 20:03:09 by femaury           #+#    #+#              #
#    Updated: 2018/11/12 15:27:05 by femaury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
SRC_PATH = srcs
SRC_NAME = asm_main.c asm_op_tab.c asm_parse.c asm_parse_head.c asm_write.c \
		   asm_parse_body.c asm_parse_body_ops.c asm_oplist_utils.c \
		   asm_lablist_utils.c asm_parse_body_2.c asm_free_utils.c
OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_PATH = incs
INC_NAME = asm.h
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))
LIB = ../libft/libft.a ../libft/ft_dprintf/libftdprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_PATH)

T = $(words $(SRC_NAME))
N = x
C = $(words $N)$(eval N := x $N)
ECHO = echo "\r[\033[33m`expr $C '*' 100 / $T`%\033[0m] \
	   Compiling \033[35m$(NAME)\033[0m...\c"

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo "\r[\033[32m100%\033[0m] \033[35m$(NAME)\033[0m is ready!   "

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $<
	@$(ECHO)

clean:
	@$(RM) $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "[\033[32mOK\033[0m] $(NAME) objects cleaned."

fclean: clean
	@$(RM) $(NAME)
	@echo "[\033[32mOK\033[0m] $(NAME) \033[31mhas been removed.\033[0m"
ifeq ($(MAKECMDGOALS), re)
	@echo ""
endif

re: fclean all
