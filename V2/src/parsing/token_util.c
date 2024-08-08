#include "parsing.h"

void	print_token(t_token *token)
{
	char	*str;

	if (!token)
		return ;
	if (token->type == pipes)
		str = "PIPE";
	else if (token->type == input)
		str = "INPUT";
	else if (token->type == output)
		str = "OUTPUT";
	else if (token->type == here_doc)
		str = "HERE_DOC";
	else if (token->type == word)
		str = "WORD";
	else if (token->type == dollar)
		str = "DOLLAR";
	else if (token->type == append)
		str = "APPEND";
	else if (token->type == merge)
		str = "MERGE";
	else
		str = "undefined token";
	printf("type: %s, value: ", str);
	if (token->type == word)
		printf("%s", (char *)token->value);
	else
		printf("%d", token->type);
	printf("\n");
	print_token(token->next);
}

t_token *last_token(t_token *token)
{
	if (!token)
		return (NULL);
	while (token->next)
		token = token->next;
	return (token);
}

void	destroy_token_chain(t_token **token)
{
	t_token *tmp;

	while (*token)
	{
		tmp = get_token(token);
		destroy_token(tmp);
	}
}

void	free_str_array(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}