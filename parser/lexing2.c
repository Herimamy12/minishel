/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:49:01 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/26 10:49:09 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexing.h"

void	unify_token(t_token *token)
{
	char	*m;

	while (token)
	{
		if (token->type == word && token->value->next)
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
	while ((*token)->type == type_ref)
	{
		tmp = *token;
		*token = (*token)->next;
		tmp->next = NULL;
		destroy_token(tmp);
	}
	trim_token_type(&((*token)->next), type_ref);
}