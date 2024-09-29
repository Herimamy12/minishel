/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako < nirirako@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:26:10 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 14:01:35 by nirirako         ###   ########.fr       */
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
