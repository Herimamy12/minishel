/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:28:41 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/12 08:23:59 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "utility.h"

static int	handle_word_quote(char *words, t_string **string)
{
	int	i;

	i = 0;
	while (words[i] && words[i] != '"')
		i++;
	append_string(string, ft_substr(words, 0, i));
	return (i);
}

static int	handle_double_quote(char *words, t_token **token)
{
	t_string	*string;
	char		*ptr;
	char		*m;

	ptr = words++;
	string = NULL;
	if (!ft_strchr(words, '"'))
	{
		append_token(token, new_token(word, ft_strdup("\"")));
		return (1);
	}
	while (*words && *words != '"')
		words += handle_word_quote(words, &string);
	m = assemble(string);
	append_token(token, new_token(quote, m));
	destroy_string(string);
	return (ft_strlen(ptr));
}

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
		else if (*words == '"' && f)
			words += handle_double_quote(words, &token);
		else if (*words == '"')
			words += handle_2_quote(words, &token, sh);
		else
			words += handle_words(words, &token);
	}
	return (token);
}

static int	find_here_doc(t_token *token, int flag)
{
	if (token && token->type == here_doc)
		return (1);
	if (!token || !token->prev)
		return (0);
	if (token->prev->type == here_doc)
		return (1);
	if (token->prev->type == space && token->prev->prev)
	{
		if (token->prev->prev->type == here_doc)
			return (1);
	}
	if (flag && token->type != space)
		return (1);
	return (0);
}

t_token	*tokenify(t_string *string, t_shell *sh)
{
	int		flag;
	t_token	*token;

	flag = 0;
	token = NULL;
	while (string)
	{
		if (!(is_str_empty(string)))
		{
			if (!(string->words[0] == '$' && !string->words[1] && string->next
					&& (string->next->words[0] == '"'
						|| string->next->words[0] == '\'')))
			{
				flag = find_here_doc(last_token(token), flag);
				append_token(&token, tokenize_string(string, sh, flag));
			}
		}
		else
			append_token(&token, new_token(word, ft_strdup("")));
		string = string->next;
	}
	return (token);
}
