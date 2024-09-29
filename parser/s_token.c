/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_token.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako < nirirako@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:28:13 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 14:02:16 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_token.h"
#include "utility.h"

t_token	*new_token(enum e_token type, char *value)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
	{
		report_error("Malloc error in t_token\n");
		return (NULL);
	}
	token->type = type;
	token->next = NULL;
	token->prev = NULL;
	if (value)
		token->value = new_string(value);
	else
		token->value = NULL;
	return (token);
}

t_token	*last_token(t_token *token)
{
	while (token && token->next)
		token = token->next;
	return (token);
}

void	append_token(t_token **src, t_token *token)
{
	t_token	*last;

	if (!*src)
	{
		*src = token;
		return ;
	}
	last = last_token(*src);
	last->next = token;
	token->prev = last;
}

void	destroy_token(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		tmp = token;
		token = token->next;
		if (tmp->value)
			destroy_string(tmp->value);
		free(tmp);
	}
}

void	print_token(t_token *token)
{
	while (token)
	{
		printf("[%s]", print_token_type(token->type));
		if (token->type == word || token->type == quote)
			print_string(token->value);
		printf("\n");
		token = token->next;
	}
}
