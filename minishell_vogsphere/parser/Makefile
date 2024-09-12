# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 09:01:18 by nirirako@         #+#    #+#              #
#    Updated: 2024/08/19 09:01:21 by nirirako@        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = parse

BIN_SRC = main.c

TAR_SRC = lexing0.c lexing1.c s_command1.c s_command.c s_here_doc.c\
		  s_env.c s_pipe.c s_shell.c s_stream.c s_string.c s_string1.c\
		  s_token.c slice.c token1.c token2.c token3.c token4.c utility.c\
		  utility1.c sig_handler.c s_env1.c s_env2.c lexing2.c parser.c\
		  lexing3.c parser1.c

INCLUDE = include/

LIB = ../libft/

OBJ_DIR = obj/

TAR_OBJ = $(addprefix $(OBJ_DIR)/, $(TAR_SRC:%.c=%.o))

BIN_OBJ = $(addprefix $(OBJ_DIR)/, $(BIN_SRC:%.c=%.o))

CC = cc

CFLAGS = -Wall -Wextra -Werror

IFLAGS = -I $(INCLUDE) -I $(LIB)

LFLAGS = -L $(LIB) -lft -lreadline

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(addprefix $(OBJ_DIR), src)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(BIN_OBJ) $(TAR_OBJ)
	make -C $(LIB)
	make -C $(LIB) bonus
	$(CC) -o $(NAME) $(BIN_OBJ) $(TAR_OBJ) -g $(LFLAGS)

all: $(NAME)

clean:
	make -C $(LIB) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIB) fclean
	rm -rf $(NAME)
	rm -rf libparser.a

re: fclean all

tar: $(TAR_OBJ)
	ar -rc libparser.a $(TAR_OBJ)

test: $(NAME)
	./$(NAME)

val:
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp --track-origins=yes ./$(NAME)