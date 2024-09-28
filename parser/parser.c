/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:33:17 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/29 07:58:37 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*prompt(char *line, t_shell *sh, t_token **r_token)
{
	t_token	*token;
	int		f;

	token = token_parser(line, sh, &f);
	if (token)
	{
		append_token(r_token, token);
		if (last_token(token)->type != pipes)
			return (NULL);
		report_error("Syntax error near token PIPE\n");
	}
	destroy_token(*r_token);
	*r_token = NULL;
	if (ft_strchr(line, '$') && !ft_strchr(line, '<'))
		sh->exit_code = 0;
	else
	{
		if (f)
			sh->exit_code = 2;
		else
			sh->exit_code = 1;
	}
	return ("minishell> ");
}

static t_token	*handle_eof(t_token *token)
{
	if (token)
		destroy_token(token);
	return (NULL);
}

t_token	*prompt_user(t_shell *sh)
{
	t_token	*r_token;
	char	*line;
	char	*p;

	r_token = NULL;
	p = "minishell> ";
	while (1)
	{
		line = readline(p);
		if (!line)
			return (handle_eof(r_token));
		if (ft_is_str_empty(line))
		{
			free(line);
			continue ;
		}
		add_history (line);
		p = prompt(line, sh, &r_token);
		free(line);
		if (!p)
			break ;
	}
	return (r_token);
}

t_token	*token_parser(char *cmd, t_shell *sh, int *exit_code)
{
	t_token		*old;
	t_token		*new;
	t_string	*str;
	int			f;

	str = slice(cmd);
	old = tokenify(str, sh);
	new = NULL;
	f = check_syntax(old);
	if (f)
		new = lexicalize(old, sh);
	*exit_code = f;
	destroy_string(str);
	destroy_token(old);
	return (new);
}
