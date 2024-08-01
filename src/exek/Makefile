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

NAME = libexecutor.a

BIN = executor

SRC = main.c utility.c

OBJ = $(SRC:.c=.o)

RM = rm -f

CC = gcc

AR = ar -rc

INCLUDE = ../../include/parsing/
INCLUDE1 = ../../include/exek/

LIB1 = ../../lib/libft
LIB2 = ../parsing/

CFLAGS = -Wall -Wextra -Werror

IFLAGS = -I $(INCLUDE) -I $(INCLUDE1) -I $(LIB1)

LFLAGS = -L $(LIB1) -L $(LIB2) -lparser -lft

.c.o:
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	make -C $(LIB1)
	make -C $(LIB1) bonus
	make -C $(LIB2)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
	make -C $(LIB1) clean
	make -C $(LIB2) clean
	$(RM) $(OBJ)

fclean: clean
	make -C $(LIB1) fclean
	make -C $(LIB2) fclean
	$(RM) $(NAME)
	$(RM) $(BIN)

re: fclean $(NAME)

BIN: $(OBJ)
	make -C $(LIB1)
	make -C $(LIB1) bonus
	make -C $(LIB2)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(BIN) $(OBJ) $(LFLAGS)

test: BIN
	clear
	./$(BIN)

val: BIN
	clear
	valgrind --leak-check=full --track-origins=yes ./$(BIN)
