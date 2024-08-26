/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:55:26 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/23 08:55:27 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "utility.h"

/*
	the flag f in tokenize_string is used to check wether the environnement 
	variable should be expanded or not
*/
t_token	*tokenize_string(t_string *string, t_shell *sh, int f)
{
	t_token	*token;
	char	*words;

	token = NULL;
	words = string->words;
	while (*words)
	{
		if (is_token(*words) || *words == ' ')
			words += handle_token(words, &token, f);
		else if (*words == '\'')
			words += handle_1_quote(words, &token);
		else if (*words == '"')
			words += handle_2_quote(words, &token, sh);
		else
			words += handle_words(words, &token);
	}
	return (token);
}

static int	find_here_doc(t_token *token)
{
	if (!token || !token->prev)
		return (0);
	if (token->prev->type == here_doc)
		return (1);
	if (token->prev->type == space && token->prev->prev)
	{
		if (token->prev->prev->type == here_doc)
			return (1);
	}
	return (0);
}

t_token	*tokenify(t_string *string, t_shell *sh)
{
	t_token	*token;

	token = NULL;
	while (string)
	{
		append_token(&token, tokenize_string(string, sh,
				find_here_doc(last_token(token))));
		string = string->next;
	}
	return (token);
}
