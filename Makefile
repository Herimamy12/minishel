NAME = minishell

BNAME = minishell_bonus

SRC = main.c

LIB1 = libft/

LIB2 = parser/

LIB3 = exec/

LIB_BONUS = parser_bonus/

INCLUDE1 = exec/include

INCLUDE2 = parser/include

OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

CC = cc

CFLAGS = -Wall -Wextra -Werror

IFLAGS = -I $(INCLUDE1) -I $(INCLUDE2) -I $(LIB1)

LFLAGS = -L $(LIB1) -L $(LIB2) -L $(LIB3) -lexec -lparser -lft -lreadline

LBFLAGS = -L $(LIB1) -L $(LIB_BONUS) -L $(LIB3) -lexec -lparser_bonus -lft -lreadline

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(addprefix $(OBJ_DIR), src)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIB1)
	make -C $(LIB1) bonus
	make -C $(LIB2) tar
	make -C $(LIB3) tar
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

$(BNAME): $(OBJ)
	make -C $(LIB1)
	make -C $(LIB1) bonus
	make -C $(LIB_BONUS) tar
	make -C $(LIB3) tar
	$(CC) -o $(BNAME) $(OBJ) $(LBFLAGS)

all: $(NAME)

clean:
	make -C $(LIB1) clean
	make -C $(LIB2) clean
	make -C $(LIB3) clean
	make -C $(LIB_BONUS) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIB1) fclean
	make -C $(LIB2) fclean
	make -C $(LIB3) fclean
	make -C $(LIB_BONUS) fclean
	rm -rf $(NAME) $(BNAME)

re: fclean all

bonus: $(BNAME)