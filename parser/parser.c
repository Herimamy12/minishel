/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:49:20 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/20 12:49:29 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parser.h"

t_token	*cmd_parser(char *str_cmd, t_shell *sh)
{
	t_token		*token;
	t_token		*r_token;
	t_string	*string;

	string = slice(str_cmd);
	token = tokenify(string, sh);
	r_token = lexicalize(token, sh);
	destroy_token(token);
	destroy_string(string);
	return (r_token);
}

static void	handle_io(t_command *cmd, t_token *old, t_stream *stream)
{
	if (ft_is_input_stream(old))
		insert_input(cmd, stream);
	else
		insert_output(cmd, stream);
}

void	populate_command(t_command **cmd, t_token *token, t_shell *sh)
{
	t_token		*old;
	t_command	*curr_cmd;

	curr_cmd = last_command(*cmd);
	while (token)
	{
		if (ft_is_input_stream(token) || ft_is_output_stream(token))
		{
			old = token;
			token = token->next;
			handle_io(curr_cmd, old,
				new_stream(old->type, token->value->words, sh));
		}
		else if (token->type == pipes)
		{
			append_command(cmd, new_command());
			curr_cmd = last_command(*cmd);
		}
		else
			insert_args(curr_cmd, ft_lstnew(ft_strdup(token->value->words)));
		token = token->next;
	}
}

void	expand_here_doc(t_here_doc *hd)
{
	t_string	*str;

	str = hd->value;
	hd->hd_pipe = new_pipe();
	while (str)
	{
		ft_putstr_fd(str->words, hd->hd_pipe->fds[1]);
		ft_putstr_fd("\n", hd->hd_pipe->fds[1]);
		str = str->next;
	}
}

t_command	*cmd_builder(t_token *token, t_shell *sh)
{
	t_command	*cmd;
	t_command	*ptr;
	t_stream	*last;

	cmd = new_command();
	populate_command(&cmd, token, sh);
	ptr = cmd;
	while (ptr)
	{
		last = last_stream(ptr->io[0]);
		if (last && last->type == here_doc)
			expand_here_doc((t_here_doc *)last->value);
		ptr = ptr->next;
	}
	return (cmd);
}
