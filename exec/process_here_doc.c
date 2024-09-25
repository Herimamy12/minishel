/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_here_doc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:06:50 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/27 13:07:05 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "s_here_doc.h"
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
	if (!words[i] || (words[i] != '?' && words[i] != '_'
			&& !ft_isalnum(words[i])))
	{
		append_string(string, ft_strdup("$"));
		return (1);
	}
	while (words[i] && words[i] != '"' && words[i] != '$' && words[i] != 32)
	{
		if (words[i] != '_' && !ft_isalnum(words[i]))
		{
			if (words[i] == '?' && i == 1)
				i++;
			break ;
		}
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

void	handle_here_doc(char *lim, t_shell *sh, int out_fd, int f)
{
	char	*line;
	char	*string;

	while (1)
	{
		line = readline("here_doc> ");
		if (!ft_strcmp(line, lim))
			break ;
		if (!line)
		{
			report_error("Waring: here-document delimited by end-of-file [");
			report_error(lim);
			report_error("] wanted\n");
			break ;
		}
		if (f)
			string = expand_hd_str(line, sh);
		else
			string = ft_strdup(line);
		ft_putstr_fd(string, out_fd);
		ft_putstr_fd("\n", out_fd);
		free(string);
		free(line);
	}
	free(line);
}
