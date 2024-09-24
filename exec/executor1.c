/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:03:41 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/23 09:03:48 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	close_all_pipe_except(t_command *cmd)
{
	while (cmd && cmd->pipes)
	{
		close_pipe(cmd->pipes);
		cmd = cmd->next;
	}
}

void	close_pipe_stream(t_command *cmd)
{
	t_stream	*stream;
	t_here_doc	*hd;

	while (cmd)
	{
		stream = cmd->stream;
		while (stream)
		{
			if (stream->type == here_doc)
			{
				hd = (t_here_doc *)stream->value;
				close_pipe(hd->pipe);
			}
			stream = stream->next;
		}
		cmd = cmd->next;
	}
}

void	ft_execute(t_command *cmd, t_data *data)
{
	int		n;
	int		exit_code;
	char	**env;
	char	**arg;
	t_list	*lst;

	lst = env_2_lst(data->sh->env);
	env = lst_2_str(lst);
	arg = lst_2_str(cmd->args);
	n = is_builtins(cmd);
	exit_code = EXIT_SUCCESS;
	if (n == 0)
		exit_code = ft_execvpe(arg, env);
	else
		exit_code = handle_builtins(arg, n, data->sh);
	free_str_array(arg);
	free_str_array(env);
	destroy_data(data);
	if (lst)
		ft_lstclear(&lst, &free);
	exit(exit_code);
}

static int	expand_here_doc(t_command *cmd, t_data *data)
{
	t_stream	*stream;

	while (cmd)
	{
		stream = cmd->stream;
		while (stream)
		{
			if (stream->type == here_doc && get_here_doc
				((t_here_doc *)stream->value, data) != EXIT_SUCCESS)
				return (0);
			stream = stream->next;
		}
		cmd = cmd->next;
	}
	return (1);
}

int	cmd_executor(t_data *data)
{
	t_token		*token;
	t_command	*cmd;

	token = prompt_user(data->sh);
	data->token = NULL;
	if (!token)
		return (0);
	cmd = parse_command(token);
	data->cmd = cmd;
	data->token = token;
	if (!expand_here_doc(cmd, data))
		data->sh->exit_code = 130;
	else if (data->cmd->args && !data->cmd->next && !ft_strcmp
		(data->cmd->args->content, "exit"))
		handle_exit (data);
	else
		launch_cmd(cmd, data);
	destroy_command(cmd);
	destroy_token(token);
	data->cmd = NULL;
	return (1);
}
