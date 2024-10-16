/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:25:49 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/16 09:14:09 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexing.h"
#include "wildcard.h"

static t_token	*file2token(t_file *f)
{
	t_token	*token;
	char	*path_name;

	token = NULL;
	while (f)
	{
		path_name = f->path_name;
		if (path_name[0] && path_name[1] && path_name[0] == '.' && path_name[1] == '/')
			path_name += 2;
		append_token(&token, new_token(word, ft_strdup(path_name)));
		f = f->next;
	}
	return (token);
}

void	link_token(t_token *token)
{
	t_token	*prev;

	prev = token;
	token = token->next;
	while (token)
	{
		token->prev = prev;
		prev = token;
		token = token->next;
	}
}

t_token	*expand_wildcard(char *pattern)
{
	t_file	*f;
	t_token	*token;

	f = wild_expand(pattern);
	token = file2token(f);
	destroy_file(f);
	return (token);
}

static t_token	*insert2chain(t_token **ptr, t_token *new, t_token *token)
{
	t_token	*tmp;

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

void	handle_wildcard(t_token *new, t_token **ptr)
{
	t_token	*token;

	link_token(new);
	while (new)
	{
		if (is_word(new->type) && ft_strchr(new->value->words, '*')
			&& (!new->prev || (new->prev && !is_stream(new->prev->type))))
		{
			token = expand_wildcard(new->value->words);
			new = insert2chain(ptr, new, token);
		}
		// else if (is_word(new->type))
		// 	unescape_char(new->value->words);
		new = new->next;
	}
}
