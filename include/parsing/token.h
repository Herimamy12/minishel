#ifndef TOKEN_H
# define TOKEN_H
# define N_MAX 8
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

enum e_token
{
	pipes = '|',
	input = '<',
	output = '>',
	here_doc = input - 40,
	word = 1, 
	dollar = '$',
	append = output - 40,
	merge = 2
};

typedef struct s_token
{
	enum e_token type;
	void	*value;
	struct s_token *next;
}	t_token;

t_token	*new_token(enum e_token type, void *value);
void	destroy_token(t_token *token);
t_token *get_token(t_token **token);
void	print_token(t_token *token);
void	insert_token(t_token **src, t_token *token);
t_token *last_token(t_token *token);
// token parsing
void	destroy_token_chain(t_token **token);
int check_syntax(t_token *token);
#endif