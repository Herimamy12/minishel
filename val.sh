make bonus
clear
valgrind --leak-check=full --track-origins=yes --track-fds=yes --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ./minishell_bonus
