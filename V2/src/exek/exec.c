/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:21:01 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/08 08:21:09 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	link_2_next(int next_cmd, int stream, int fds[2])
{
		if (stream == STDIN_FILENO)
		{
			close(fds[1]);
			if (!next_cmd)
				dup2(fds[0], STDIN_FILENO);
			close(fds[0]);
		}
		else
		{
			close(fds[0]);
			if (!next_cmd)
				dup2(fds[1], STDOUT_FILENO);
			close(fds[1]);
		}
}

void	run_command(t_command *cmd, t_data *data, int f)
{
		int	n;
		int exit_code;
		char	**env;
		char	**arg;

		env = lst_2_str(data->sh->env);
		arg = lst_2_str(cmd->args);
		n = is_builtins(cmd);
		exit_code = EXIT_SUCCESS;
		if (n == 0)
			exit_code = ft_execvpe(arg, env);
		else
			exit_code = handle_builtins(arg, n, data->sh);
		free_str_array(arg);
		free_str_array(env);
		if (f)
		{
			destroy_data(data);
			exit(exit_code);
		}
}

void reset_std_stream(t_shell *sh)
{
	dup2(sh->stdin, 0);
	dup2(sh->stdout, 1);
}

void sig_handler(int signum)
{
	(void)signum;
	printf("^C has been pressed\n");
}

void set_signal(int signum, int handler)
{
	struct sigaction sa;

	(void) signum;
	ft_memset(&sa, 0, sizeof(sa));
	if (handler == IGNORE)
		sa.sa_handler = SIG_IGN;
	else if (handler == DEFAULT)
		sa.sa_handler = SIG_DFL;
	else
		sa.sa_handler = &sig_handler;
	sigaction(SIGINT, &sa, NULL);
}

int	execute(t_command *usr_cmd, t_data *data)
{
	t_command	*cmd;
	int	fds[2];
	int child_pid;
	int exit_status;

	cmd = usr_cmd;
	while (cmd)
	{
		pipe(fds);
		if (set_input_stream(cmd->io[0], data) && set_output_stream(cmd->io[1], data))
		{
			child_pid = fork();
			if (child_pid == 0)
			{
				set_signal(SIGINT, DEFAULT);
				link_2_next(cmd->next == NULL, STDOUT_FILENO, fds);
				run_command(cmd, data, 1);
			}
		}
		cmd = cmd->next;
		reset_std_stream(data->sh);
		link_2_next(cmd == NULL, STDIN_FILENO, fds);
	}
	set_signal(SIGINT, IGNORE);
	exit_status = waitpid(child_pid, NULL, 0);
	if (!usr_cmd->next && is_builtins(usr_cmd) > 0)
		run_command(usr_cmd, data, 0);
	data->sh->exit_code = WEXITSTATUS(exit_status);
	return (1);
}
