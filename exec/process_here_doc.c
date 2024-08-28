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
	if (words[i] == '$' || words[i] == ' ')
	{
		append_string(string, ft_strdup("$"));
		return (1);
	}
	while (words[i] && words[i] != '"' && words[i] != '$' && words[i] != 32)
	{
		if (words[i] == '?')
		{
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

static void	handle_here_doc(char *lim, t_shell *sh, int out_fd)
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
		string = expand_hd_str(line, sh);
		ft_putstr_fd(string, out_fd);
		ft_putstr_fd("\n", out_fd);
		free(string);
		free(line);
	}
	free(line);
}

int	get_here_doc(t_here_doc *hd, t_data *data)
{
	int	pid;
	int	exit_status;

	pid = fork();
	if (pid == 0)
	{
		set_signal(SIGINT, DEFAULT);
		close(hd->pipe->fds[0]);
		handle_here_doc(hd->lim, data->sh, hd->pipe->fds[1]);
		destroy_data(data);
		exit(EXIT_SUCCESS);
	}
	set_signal(SIGINT, IGNORE);
	waitpid(pid, &exit_status, 0);
	if (WIFEXITED(exit_status))
		return (WEXITSTATUS(exit_status));
	return (130);
}
