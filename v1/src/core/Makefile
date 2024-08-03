# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 13:12:26 by nirirako@         #+#    #+#              #
#    Updated: 2024/03/08 13:12:45 by nirirako@        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c

OBJ = $(SRC:.c=.o)

RM = rm -f

CC = gcc

INCLUDE = ../../include/parsing/
INCLUDE1 = ../../include/exek/
INCLUDE2 = ../../include/core/

LIB1 = ../../lib/libft
LIB2 = ../parsing/
LIB3 = ../exek/

CFLAGS = -Wall -Wextra -Werror

IFLAGS = -I $(INCLUDE) -I $(INCLUDE1) -I $(INCLUDE2) -I $(LIB1)

LFLAGS = -L $(LIB1) -L $(LIB2) -L $(LIB3) -lexecutor -lparser -lft -lreadline

.c.o:
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	make -C $(LIB1)
	make -C $(LIB1) bonus
	make -C $(LIB2)
	make -C $(LIB3)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

all: $(NAME)

clean:
	make -C $(LIB1) clean
	make -C $(LIB2) clean
	$(RM) $(OBJ)

fclean: clean
	make -C $(LIB1) fclean
	make -C $(LIB2) fclean
	make -C $(LIB3) fclean
	$(RM) $(NAME)
	clear

re: fclean $(NAME)

test: all
	clear
	./$(NAME)

val: all
	clear
	valgrind --leak-check=full --track-origins=yes ./$(NAME)
