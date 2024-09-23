# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nirirako <nirirako@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 09:01:18 by nirirako@         #+#    #+#              #
#    Updated: 2024/08/24 09:53:14 by nirirako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c

LIB1 = libft/

LIB2 = parser/

LIB3 = exec/

INCLUDE1 = exec/include

INCLUDE2 = parser/include

OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

CC = cc

CFLAGS = -Wall -Wextra -Werror

IFLAGS = -I $(INCLUDE1) -I $(INCLUDE2) -I $(LIB1)

LFLAGS = -L $(LIB1) -L $(LIB2) -L $(LIB3) -lexec -lparser -lft -lreadline

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(addprefix $(OBJ_DIR), src)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIB1)
	make -C $(LIB1) bonus
	make -C $(LIB2) tar
	make -C $(LIB3) tar
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

all: $(NAME)

clean:
	make -C $(LIB1) clean
	make -C $(LIB2) clean
	make -C $(LIB3) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIB1) fclean
	make -C $(LIB2) fclean
	make -C $(LIB3) fclean
	rm -rf $(NAME)

re: fclean all