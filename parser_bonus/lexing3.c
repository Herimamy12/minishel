/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:25:49 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/14 10:36:51 by nirirako         ###   ########.fr       */
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

static int	is_word(enum e_token type)
{
	return (type == word || type == quote);
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

static t_token *file2token(t_file *f)
{
	t_token *token;

	token = NULL;
	while (f)
	{
		append_token(&token, new_token(word, ft_strdup(f->path_name)));
		f = f->next;
	}
	return (token);
}

void	link_token(t_token *token)
{
	t_token *prev;

	prev = token;
	token = token->next;
	while (token)
	{
		token->prev = prev;
		prev = token;
		token = token->next;
	}
}

t_token *expand_wildcard(char *pattern)
{
	t_file *f;
	t_token *token;

	f = wild_expand(pattern);
	token = file2token(f);
	destroy_file(f);
	return (token);
}

static t_token	*insert2chain(t_token **ptr, t_token *new, t_token *token)
{
	t_token *tmp;

	tmp = new;
	new = new->prev;
	if (new)
	{
		new->next = token;
		token->prev = new;
	}
	else
	{
		*ptr = token;
		token->next = tmp->next;
	}
	last_token(token)->next = tmp->next;
	tmp->next = NULL;
	destroy_token(tmp);
	return (token);
}

static void handle_wildcard(t_token *new, t_token **ptr)
{
	t_token *token;

	link_token(new);
	while (new)
	{
		if (is_word(new->type) && ft_strchr(new->value->words, '*')
			&& (!new->prev || (new->prev && !is_stream(new->prev->type))))
		{
			token = expand_wildcard(new->value->words);
			new = insert2chain(ptr, new, token);
		}
		else
			unescape_char(new->value->words);
		new = new->next;
	}
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
