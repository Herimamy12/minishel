/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:26:10 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/18 09:29:39 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	handle_io(t_command *cmd, t_token *token, enum e_token type)
{
	t_here_doc	*hd;

	append_stream(&cmd->stream, new_stream(type, token->value->words));
	if (type == here_doc)
	{
		if (token->type == quote)
		{
			hd = (t_here_doc *)last_stream(cmd->stream)->value;
			hd->expand = 0;
		}
	}
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
		{
			if (!append_command(&ptr, new_command()))
				break ;
		}
		else if (token->value)
			insert_args(cmd, ft_lstnew(ft_strdup(token->value->words)));
		token = token->next;
	}
	return (ptr);
}

t_command	*command_parser(char *str_cmd, t_shell *sh)
{
	t_token		*token;
	t_command	*cmd;
	int			exit_code;

	token = token_parser(str_cmd, sh, &exit_code);
	cmd = parse_command(token);
	destroy_token(token);
	return (cmd);
}
