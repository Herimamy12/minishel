#include "parsing.h"

t_token	*new_token(enum e_token type, void *value)
{
	t_token *token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = value;
	token->next = NULL;
	return (token);
}

void	destroy_token(t_token *token)
{
	if (token->type == word && token->value)
		free(token->value);
	free(token);
}

t_token *get_token(t_token **token)
{
	t_token *tmp;

	if (!*token)
		return (NULL);
	tmp = *token;
	*token = tmp->next;
	tmp->next = NULL;
	return (tmp);
}

void	insert_token(t_token **src, t_token *token)
{
	if (!*src)
	{
		*src = token;
		return ;
	}
	last_token(*src)->next = token;
}