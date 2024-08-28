/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:33:17 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/27 13:33:25 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	handle_io(t_command *cmd, t_token *token, enum e_token type)
{
	append_stream(&cmd->stream, new_stream(type, token->value->words));
}

static char	*prompt(char *line, t_shell *sh, t_token **r_token)
{
	t_token	*token;

	token = token_parser(line, sh);
	if (token)
	{
		append_token(r_token, token);
		if (last_token(token)->type != pipes)
			return (NULL);
		return ("> ");
	}
	destroy_token(*r_token);
	*r_token = NULL;
	return ("minishell> ");
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
			return (NULL);
		add_history (line);
		p = prompt(line, sh, &r_token);
		free(line);
		if (!p)
			break ;
	}
	return (r_token);
}

t_token	*token_parser(char *cmd, t_shell *sh)
{
	t_token		*old;
	t_token		*new;
	t_string	*str;

	str = slice(cmd);
	old = tokenify(str, sh);
	new = lexicalize(old, sh);
	destroy_string(str);
	destroy_token(old);
	return (new);
}

t_command	*parse_command(t_token *token)
{
	t_command		*cmd;
	t_command		*ptr;
	enum e_token	type;

	ptr = new_command();
	while (token)
	{
		cmd = last_command(ptr);
		if (is_stream(token->type))
		{
			type = token->type;
			token = token->next;
			handle_io(cmd, token, type);
		}
		else if (token->type == pipes)
			append_command(&ptr, new_command());
		else if (token->value->words[0])
			insert_args(cmd, ft_lstnew(ft_strdup(token->value->words)));
		token = token->next;
	}
	return (ptr);
}
