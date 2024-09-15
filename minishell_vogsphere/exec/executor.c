/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:05:59 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/23 09:06:02 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	child(t_command *cmd, t_data *data)
{
	set_signal(SIGINT, DEFAULT);
	set_signal(SIGQUIT, DEFAULT);
	close_all_pipe_except(cmd->next);
	if (cmd->next)
		set_pipe_2_output(cmd->pipes);
	if (cmd->prev)
		set_pipe_2_input(cmd->prev->pipes);
	if (!set_io_stream(cmd))
	{
		destroy_data(data);
		exit(EXIT_FAILURE);
	}
	close_pipe_stream(cmd->next);
	ft_execute(cmd, data);
}

int	wait_command(t_data *data)
{
	t_command	*cmd;
	int			exit_status;

	cmd = data->cmd;
	if (g_sigint_count)
		g_sigint_count = 0;
	while (cmd)
	{
		waitpid(cmd->pid, &exit_status, 0);
		cmd = cmd->next;
	}
	return (exit_status);
}

void	fork_cmd_chain(t_command *user_cmd, t_data *data)
{
	int			pid;
	t_command	*cmd;

	while (user_cmd)
	{
		pid = fork();
		if (!pid)
			child(user_cmd, data);
		else
		{
			user_cmd->pid = pid;
			if (user_cmd->prev)
				close_pipe(user_cmd->prev->pipes);
		}
		cmd = user_cmd;
		user_cmd = user_cmd->next;
		cmd->next = NULL;
		close_pipe_stream(cmd);
		cmd->next = user_cmd;
	}
}
