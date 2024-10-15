
NAME = parse

LIBNAME = libparser.a

BIN_SRC = main.c

TAR_SRC = lexing0.c lexing1.c s_command1.c s_command.c s_here_doc.c\
		  s_env.c s_pipe.c s_shell.c s_stream.c s_string.c s_string1.c\
		  s_token.c token1.c token2.c token3.c token4.c utility.c\
		  utility1.c sig_handler.c s_env1.c s_env2.c lexing2.c parser.c\
		  lexing3.c parser1.c s_env3.c slice.c

INCLUDE = include/

LIB = ../libft/

OBJ_DIR = obj/

TAR_OBJ = $(addprefix $(OBJ_DIR)/, $(TAR_SRC:%.c=%.o))

TAR_OBJ1 = $(addprefix $(OBJ_DIR)/, $(TAR_SRC1:%.c=%.o))

TAR_BONUS_OBJ = $(addprefix $(OBJ_DIR)/, $(TAR_BONUS_SRC:%.c=%.o))

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
	$(CC) -o $(NAME) $(BIN_OBJ) $(TAR_OBJ) $(TAR_OBJ1) -g $(LFLAGS)

all: $(NAME)

clean:
	make -C $(LIB) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIB) fclean
	rm -rf $(NAME) ${LIBNAME} ${LIBNAME_BONUS}

re: fclean all

tar : ${LIBNAME}

${LIBNAME} : $(TAR_OBJ)
	ar -rc $@ $(TAR_OBJ)


test: $(NAME)
	./parse
