/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:25:40 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/12 08:23:04 by nirirako         ###   ########.fr       */
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
	if (is_stream(token->type))
		return (wc != 1);
	if (token && token->type == space)
	{
		token = token->prev;
		if (token && is_stream(token->type))
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

/*
	get_string is used to check wether after var env expansion, the shell should
	split the value of the variable or not. In our case, it is used to handle
	export correctly
	 * export var="abc def"
	 * export vars=$var    -> in bash, vars and var are equal because $var isn't
					expanded
	 * export	$var=$var		-> in bash, var is expanded in this context
*/
static t_string	*get_string(t_token *token, char *var)
{
	if (token->prev)
	{
		if (token->prev->type == word && token->prev->value)
		{
			if (token->prev->value->words
				&& token->prev->value->words[0] == '=')
			{
				token = token->prev;
				if (token->prev && token->prev->prev)
				{
					if (token->prev->prev->type != dollar)
						return (new_string(ft_strdup(var)));
				}
			}
		}
	}
	return (slice(var));
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
	str = get_string(token, var);
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
