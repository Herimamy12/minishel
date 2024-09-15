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
NAME = exec

BIN_SRC = main.c

TAR_SRC = builtins.c builtins1.c builtins2.c executor.c exec_util.c builtins4.c\
		  stream.c s_data.c utility.c executor1.c builtins3.c process_here_doc.c\
		  exec_utils.c process_here_doc1.c executor2.c

INCLUDE = include/

INCLUDE1 = ../parser/include/

LIB = ../libft/

LIB1 = ../parser/

OBJ_DIR = obj/

TAR_OBJ = $(addprefix $(OBJ_DIR)/, $(TAR_SRC:%.c=%.o))

BIN_OBJ = $(addprefix $(OBJ_DIR)/, $(BIN_SRC:%.c=%.o))

CC = cc

CFLAGS = -Wall -Wextra -Werror

IFLAGS = -I $(INCLUDE) -I $(INCLUDE1) -I $(LIB)

LFLAGS = -L $(LIB) -L $(LIB1) -lparser -lft -lreadline

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(addprefix $(OBJ_DIR), src)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(BIN_OBJ) $(TAR_OBJ)
	make -C $(LIB)
	make -C $(LIB) bonus
	make -C $(LIB1) tar
	$(CC) -o $(NAME) $(BIN_OBJ) $(TAR_OBJ) -g $(LFLAGS)

all: $(NAME)

clean:
	make -C $(LIB) clean
	make -C $(LIB1) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIB) fclean
	make -C $(LIB1) fclean
	rm -rf $(NAME)
	rm -rf libexec.a

re: fclean all

tar: $(TAR_OBJ)
	ar -rc libexec.a $(TAR_OBJ)

test: $(NAME)
	./$(NAME)

val:
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp --track-origins=yes ./$(NAME)