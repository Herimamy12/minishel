/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:52:34 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/23 08:52:35 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

static int	handle_input(char *words, t_token **token)
{
	words++;
	if (*words == '<')
	{
		append_token(token, new_token(here_doc, NULL));
		return (2);
	}
	append_token(token, new_token(input, NULL));
	return (1);
}

static int	handle_output(char *words, t_token **token)
{
	words++;
	if (*words == '>')
	{
		append_token(token, new_token(append, NULL));
		return (2);
	}
	append_token(token, new_token(output, NULL));
	return (1);
}

static int	handle_dollar(char *words, t_token **token, int f)
{
	words++;
	if (*words == 0 || *words == '$' || f)
	{
		append_token(token, new_token(word, ft_strdup("$")));
		if (f)
			return (1);
		return (2);
	}
	append_token(token, new_token(dollar, NULL));
	if (*words == '?')
	{
		append_token(token, new_token(word, ft_strdup("?")));
		return (2);
	}
	return (1);
}

static int	handle_others(char k, t_token **token)
{
	if (k == '|')
		append_token(token, new_token(pipes, NULL));
	else
		append_token(token, new_token(space, NULL));
	return (1);
}

int	handle_token(char *words, t_token **token, int f)
{
	if (*words == '<')
		return (handle_input(words, token));
	else if (*words == '>')
		return (handle_output(words, token));
	else if (*words == '$')
		return (handle_dollar(words, token, f));
	else
		return (handle_others(*words, token));
}
