# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsung <rsung@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 12:49:48 by rsung             #+#    #+#              #
#    Updated: 2023/07/05 11:19:50 by rsung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRC = srcs/ft_strlen.s srcs/ft_strcpy.s srcs/ft_strcmp.s srcs/ft_write.s srcs/ft_read.s srcs/ft_strdup.s

OBJ = $(SRC:srcs/%.s=objs/%.o)

NASM = nasm

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

MAIN = srcs/main.c

EXEC = myTest

NASM_FLAGS = -f elf64

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

objs/%.o: srcs/%.s
	mkdir -p objs
	$(NASM) $(NASM_FLAGS) $< -o $@

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -rf objs

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(EXEC)

re: fclean all

$(EXEC): $(NAME)
		$(CC) $(CFLAGS) $(MAIN) -L. -lasm -o $(EXEC)

.PHONY: all clean fclean re

test: $(EXEC)
