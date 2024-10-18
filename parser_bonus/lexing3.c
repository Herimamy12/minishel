/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:25:49 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/18 09:25:53 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexing.h"
#include "wildcard.h"

static void	link_2_bloc(t_token *token)
{
	t_token	*tmp;

	tmp = token->next;
	token->next = tmp->next;
	last_string(token->value)->next = tmp->value;
	if (tmp->type == quote)
		token->type = quote;
	free(tmp);
}

static void	assemble_token(t_token *token)
{
	while (token)
	{
		if (is_word(token->type) && token->next && is_word(token->next->type))
			link_2_bloc(token);
		else
			token = token->next;
	}
}

int	is_word(enum e_token type)
{
	return (type == word || type == quote);
}

t_token	*lexicalize(t_token *token, t_shell *sh)
{
	t_token	*new;
	char	*m;

	new = NULL;
	if (!expand_token(token, sh))
		return (NULL);
	assemble_token(token);
	while (token)
	{
		if (token->type == word || token->type == quote)
		{
			m = assemble(token->value);
			append_token(&new, new_token(token->type, m));
		}
		else if (token->type != dollar)
			append_token(&new, new_token(token->type, NULL));
		token = token->next;
	}
	assemble_token(new);
	trim_token_type(&new, space);
	unify_token(new);
	handle_wildcard(new, &new);
	return (new);
}
