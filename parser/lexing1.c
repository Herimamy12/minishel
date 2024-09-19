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
	if (!token->prev)
		return (0);
	token = token->prev;
	if (token->prev && is_stream(token->prev->type))
		return (wc != 1);
	if (token->prev && token->prev->type == space)
	{
		token = token->prev;
		if (token && token->prev && is_stream(token->prev->type))
			return (wc != 1);
	}
	return (0);
}

t_token	*str2token(t_string *str)
{
	t_token	*token;

	token = NULL;
	while (str)
	{
		if (!is_str_whitespace(str))
			append_token(&token, new_token(word, ft_strdup(str->words)));
		else
			append_token(&token, new_token(space, NULL));
		str = str->next;
	}
	return (token);
}

static int	extend_token(t_token *token, t_token *next, char *var)
{
	t_token		*tmp_token;
	t_string	*str;

	if (check_for_ambiguity(token, var))
	{
		report_error("$");
		report_error(next->value->words);
		report_error(": Ambiguous redirect\n");
		return (0);
	}
	str = slice(var);
	tmp_token = str2token(str);
	if (tmp_token)
	{
		token->next = tmp_token;
		last_token(tmp_token)->next = next->next;
	}
	else
		token->next = next->next;
	if (next->next)
		next->next->prev = token->next;
	destroy_string(str);
	return (1);
}

int	expand_token(t_token *token, t_shell *sh)
{
	char	*var;
	t_token	*next;

	while (token)
	{
		if (token->type == dollar)
		{
			next = token->next;
			var = expand(next->value->words, sh);
			if (!extend_token(token, next, var))
			{
				free(var);
				return (0);
			}
			next->next = NULL;
			destroy_token(next);
			free(var);
		}
		token = token->next;
	}
	return (1);
}
