/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:54:22 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/23 08:54:23 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "utility.h"

static int	handle_dollar_quote(char *words, t_string **string, t_shell *sh)
{
	int		i;
	char	*var;

	i = 0;
	if (!ft_isalnum(words[i]) && words[i] != '?' && words[i] != '_')
	{
		append_string(string, ft_strdup("$"));
		if (words[i] == ' ')
			return (0);
		return (1);
	}
	while (words[i] && words[i] != '"' && words[i] != '$' && words[i] != 32)
	{
		if (words[i] != '?' && !ft_isalnum(words[i]))
			break ;
		if ((words[i] == '?' && i == 0 && i++) || words[i] == '?')
			break ;
		else
			i++;
	}
	var = ft_substr(words, 0, i);
	append_string(string, expand(var, sh));
	free(var);
	return (i);
}

static int	handle_word_quote(char *words, t_string **string)
{
	int	i;

	i = 0;
	while (words[i] && words[i] != '"' && words[i] != '$')
		i++;
	append_string(string, ft_substr(words, 0, i));
	return (i);
}

int	handle_2_quote(char *words, t_token **token, t_shell *sh)
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
	{
		words += handle_word_quote(words, &string);
		if (*words == '$')
		{
			words++;
			words += handle_dollar_quote(words, &string, sh);
		}
	}
	m = assemble(string);
	append_token(token, new_token(quote, m));
	destroy_string(string);
	return (ft_strlen(ptr));
}
