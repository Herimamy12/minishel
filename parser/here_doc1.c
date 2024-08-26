/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:03:17 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/21 11:03:28 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "here_doc.h"
#include "utility.h"

static int	handle_word_hd(char *words, t_string **string)
{
	int	i;

	i = 0;
	while (words[i] && words[i] != '$')
		i++;
	append_string(string, ft_substr(words, 0, i));
	return (i);
}

static int	handle_dollar_hd(char *words, t_string **string, t_shell *sh)
{
	int		i;
	char	*var;

	i = 1;
	if (words[i] == '$' || words[i] == ' ')
	{
		append_string(string, ft_strdup("$"));
		return (1);
	}
	while (words[i] && words[i] != '"' && words[i] != '$' && words[i] != 32)
	{
		if (words[i] == '?')
			break ;
		i++;
	}
	var = ft_substr(words, 0, i);
	append_string(string, expand(var, sh));
	free(var);
	return (i);
}

static char	*expand_hd_str(char *words, t_shell *sh)
{
	t_string	*string;
	char		*m;

	string = NULL;
	while (*words)
	{
		words += handle_word_hd(words, &string);
		if (*words == '$')
			words += handle_dollar_hd(words, &string, sh);
	}
	m = assemble(string);
	destroy_string(string);
	return (m);
}

t_string	*handle_here_doc(char *lim, t_shell *sh)
{
	char		*line;
	t_string	*string;

	string = NULL;
	while (1)
	{
		line = readline("here_doc> ");
		if (!ft_strcmp(line, lim))
			break ;
		if (!line)
		{
			printf("Waring: here-document delimited by end-of-file");
			printf("(wanted `%s`)\n", lim);
			break ;
		}
		append_string(&string, expand_hd_str(line, sh));
		free(line);
	}
	free(line);
	return (string);
}
