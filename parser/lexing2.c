/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako < nirirako@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:25:44 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 14:01:26 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexing.h"

void	unify_token(t_token *token)
{
	char	*m;

	while (token)
	{
		if ((token->type == word || token->type == quote) && token->value->next)
		{
			m = assemble(token->value);
			free(token->value->words);
			token->value->words = m;
		}
		token = token->next;
	}
}

void	trim_token_type(t_token **token, enum e_token type_ref)
{
	t_token	*tmp;

	if (!token || !*token)
		return ;
	while ((*token)->next && (*token)->type == type_ref)
	{
		tmp = *token;
		*token = (*token)->next;
		tmp->next = NULL;
		destroy_token(tmp);
	}
	trim_token_type(&((*token)->next), type_ref);
}
