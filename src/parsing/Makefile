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

NAME = libparser.a

BIN = parse

SRC = token.c token_util.c handler_util.c handler.c s_shell.c\
		lexer.c s_stream.c s_command_1.c s_command_2.c syntax_checker.c\
		handler_utils.c

BIN_SRC = main.c

OBJ = $(SRC:.c=.o)
BIN_OBJ = $(BIN_SRC:.c=.o)

RM = rm -f

CC = gcc

AR = ar -rc

INCLUDE = ../../include/parsing/

LIB1 = ../../lib/libft

CFLAGS = -Wall -Wextra -Werror

IFLAGS = -I $(INCLUDE) -I $(LIB1)

LFLAGS = -L $(LIB1) -lft

.c.o:
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	make -C $(LIB1)
	make -C $(LIB1) bonus
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
	make -C $(LIB1) clean
	$(RM) main.o
	$(RM) $(OBJ)

fclean: clean
	make -C $(LIB1) fclean
	$(RM) $(NAME)
	$(RM) $(BIN)

re: fclean $(NAME)

BIN: $(OBJ) $(BIN_OBJ)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(BIN) $(BIN_OBJ) $(OBJ) $(LFLAGS)

test: BIN
	clear
	./$(BIN)

val: BIN
	clear
	valgrind --leak-check=full --track-origins=yes ./$(BIN)
