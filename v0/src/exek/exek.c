/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:29:52 by nherimam          #+#    #+#             */
/*   Updated: 2024/08/02 11:30:03 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exek.h"

int	run_simple_cmd(t_command *cmd, t_data *data)
{
	char	**str_cmd;
	char	**str_env;
	pid_t	pid;

	str_env = lst_2_str(data->sh->env);
	if (!set_input_stream(cmd->io[0], data) || !set_output_stream(cmd->io[1], data))
		return (EXIT_FAILURE);
	str_cmd = lst_2_str(cmd->args);
	if (str_cmd[0])
	{
		pid = fork();
		if (pid == 0)
		{
			execvp(str_cmd[0], str_cmd);
			perror(str_cmd[0]);
			return (EXIT_FAILURE);
		}
		else
			wait(NULL);
	}
	free_str_array(str_cmd);
	free_str_array(str_env);
	return (EXIT_SUCCESS);
}

void	ft_exec(t_data *data)
{
	t_command	*cmd;
	int pid;
	int fds[2];

	cmd = data->cmd;
	while (cmd->next)
	{
		pipe(fds);
		pid = fork();
		if (pid == 0)
		{
			close(fds[0]);
			dup2(fds[1], 1);
			data->sh->exit_code = run_simple_cmd(cmd, data);
			destroy_data(data);
			exit(EXIT_SUCCESS);
		}
		else
			wait(NULL);
		close(fds[1]);
		dup2(fds[0], 0);
		close(fds[0]);
		cmd = cmd->next;
	}
	run_simple_cmd(cmd, data);
}