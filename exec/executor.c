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
	set_signal(SIGINT, IGNORE);
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

void	launch_cmd(t_command *user_cmd, t_data *data)
{
	int		exit_status;
	int		type;
	char	**arg;

	type = is_builtins(user_cmd);
	if (!user_cmd->next && type != 0)
	{
		arg = lst_2_str(user_cmd->args);
		data->sh->exit_code = handle_builtins(arg, type, data->sh);
		free_str_array(arg);
	}
	else
	{
		fork_cmd_chain(user_cmd, data);
		set_signal(SIGINT, IGNORE);
		exit_status = wait_command(data);
		if (WIFEXITED(exit_status))
			data->sh->exit_code = WEXITSTATUS(exit_status);
		else
			data->sh->exit_code = 130;
	}
}
