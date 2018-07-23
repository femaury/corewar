# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: femaury <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 20:03:09 by femaury           #+#    #+#              #
#    Updated: 2018/07/07 23:29:14 by femaury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = ../libft.a
SRC_PATH = srcs
SRC_NAME = ft_printf.c ftp_parsing.c ftp_get_arg.c ftp_get_int.c \
		   ftp_fill_buffer.c ftp_pad_buffer.c ftp_get_str.c ftp_imaxtoa_base.c \
		   ftp_uimaxtoa_base.c ftp_get_wstr.c ftp_check_wstr.c ftp_colors.c
LIB_SRC_PATH = ../srcs
LIB_SRC_NAME = ft_strlen.c ft_strdel.c ft_putstr.c ft_strnclr.c ft_setlowcase.c \
			   ft_isdigit.c ft_islower.c ft_strcmp.c ft_atoi.c ft_memalloc.c \
			   ft_memset.c ft_isupper.c ft_strhasc.c ft_wcharlen.c ft_wstrlen.c \
			   ft_strnequ.c
OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_OBJ_PATH = ../objs
LIB_OBJ_NAME = $(LIB_SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
LIB_SRC = $(addprefix $(LIB_SRC_PATH)/,$(LIB_SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIB_OBJ = $(addprefix $(LIB_OBJ_PATH)/,$(LIB_OBJ_NAME))
CC = gcc
CFLAGS = -Wall -Wextra -Werror

T := $(words $(SRC_NAME))
N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo "\r[\033[33m`expr $C '*' 100 / $T`%\033[0m] \
	   Compiling \033[35mft_printf\033[0m...\c"

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@ar rc $@ $(OBJ) $(LIB_OBJ)
	@ranlib $@
	@echo "\r[\033[32m100%\033[0m] \033[35m$(NAME)\033[0m is ready!"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -Iincs -o $@ -c $<
	@$(ECHO)

$(LIBFT): $(LIB_OBJ)
	@$(MAKE) -C ../

clean:
	@$(RM) $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "[\033[32mOK\033[0m] $(NAME) objects cleaned."

fclean: clean
	@$(RM) $(NAME)
	@echo "[\033[32mOK\033[0m] $(NAME) \033[31mhas been removed.\033[0m"

re: fclean all
