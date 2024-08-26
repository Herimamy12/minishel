/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:04:36 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/20 11:04:44 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexing.h"
#include "utility.h"
#include "libft.h"

static int	check_for_ambiguity(t_token *token, char *var)
{
	int	wc;

	wc = word_count(var, ' ');
	token = token->prev;
	if (token->prev && is_stream(token->prev->type))
		return (wc != 1);
	if (token->prev && token->prev->type == space)
	{
		token = token->prev;
		if (token->prev && is_stream(token->prev->type))
			return (wc != 1);
	}
	return (0);
}

static int	expand_token(t_token *token, t_shell *sh)
{
	char	*var;
	char	*tmp;

	while (token)
	{
		if (token->type == dollar)
		{
			token = token->next;
			var = expand(token->value->words, sh);
			tmp = token->value->words;
			token->value->words = var;
			if (check_for_ambiguity(token, var))
			{
				printf("$%s: Ambigious redirect\n", tmp);
				free(tmp);
				return (0);
			}
			free(tmp);
		}
		token = token->next;
	}
	return (1);
}

static void	link_2_bloc(t_token *token)
{
	t_token	*tmp;

	tmp = token->next;
	token->next = tmp->next;
	last_string(token->value)->next = tmp->value;
	free(tmp);
}

static void	assemble_token(t_token *token)
{
	while (token)
	{
		if (token->type == word && token->next && token->next->type == word)
			link_2_bloc(token);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
		else
			token = token->next;
	}
}

t_token	*lexicalize(t_token *token, t_shell *sh)
{
	t_token	*new;
	char	*m;

	new = NULL;
	if (!check_syntax(token) || !expand_token(token, sh))
		return (NULL);
	assemble_token(token);
	while (token)
	{
		if (token->type == word)
		{
			m = assemble(token->value);
			append_token(&new, new_token(word, m));
		}
		else if (token->type != dollar)
			append_token(&new, new_token(token->type, NULL));
		token = token->next;
	}
	assemble_token(new);
	trim_token_type(&new, space);
	unify_token(new);
	return (new);
}
