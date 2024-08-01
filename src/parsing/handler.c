/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:41:48 by nirirako@         #+#    #+#             */
/*   Updated: 2024/07/30 08:42:05 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int handle_token(char *str_cmd, t_token **token)
{
	int	i;
	t_token	*last;

	i = 0;
	if (str_cmd[i] == '<' && str_cmd[i + 1] == '<')
		insert_token(token, new_token(here_doc, NULL));
	else if (str_cmd[i] == '>' && str_cmd[i + 1] == '>')
		insert_token(token, new_token(append, NULL));
	else if (str_cmd[i] == '<')
		insert_token(token, new_token(input, NULL));
	else if (str_cmd[i] == '>')
		insert_token(token, new_token(output, NULL));
	else if (str_cmd[i] == '$')
		return (handle_dollar(str_cmd + i, token));
	else if (str_cmd[i] == '|')
		insert_token(token, new_token(pipes, NULL));
	last = last_token(*token);
	if (last->type == here_doc || last->type == append)
		return (2);
	return (1);
}

int handle_word(char *str_cmd, t_token **token)
{
	int i;

	i = 0;
	while (str_cmd[i] && !ft_is_whitespace(str_cmd[i]) && !ft_is_token(str_cmd[i]))
		i++;
	insert_token(token, new_token(word, ft_substr(str_cmd, 0, i)));
	return (i);
}

int handle_simple_quote(char *str_cmd, t_token **token)
{
	int i;

	i = 1;
	if (!ft_strchr(str_cmd + i, '\''))
	{
		insert_token(token, new_token(word, ft_strdup("'")));
		return (1);
	}
	while (str_cmd[i] != '\'')
		i++;
	insert_token(token, new_token(word, ft_substr(str_cmd, 1, i - 1)));
	return (i + 1);
}

int handle_double_quote(char *str_cmd, t_token **token)
{
	int i;
	int f;

	i = 1;
	if (!ft_strchr(str_cmd + i, '"'))
	{
		insert_token(token, new_token(word, ft_strdup("\"")));
		return (1);
	}
	while (str_cmd[i] != '"')
	{
		f = 0;
		if (str_cmd[i] == '$')
		{
			i += handle_dollar(str_cmd + i, token);
			f = 1;
		}
		i += extract_word(str_cmd + i, token, f);
	}
	return (i + 1);
}

int extract_word(char *str_cmd, t_token **token, int f)
{
	int i;

	i = 0;
	while (str_cmd[i] != '$' && str_cmd[i] != '"')
	{
		if (f && ft_is_whitespace(str_cmd[i]))
			break ;
		i++;
	}
	insert_token(token, new_token(word, ft_substr(str_cmd, 0, i)));
	return (i);
}