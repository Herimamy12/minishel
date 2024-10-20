/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:26:20 by nherimam          #+#    #+#             */
/*   Updated: 2024/09/29 13:26:25 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	handle_unexcd(t_command *user_cmd, t_data *data, int type)
{
	char	**arg;

	if (!set_io_stream(user_cmd))
		data->sh->exit_code = EXIT_FAILURE;
	else
	{
		arg = lst_2_str(user_cmd->args);
		data->sh->exit_code = handle_builtins(arg, type, data->sh);
		free_str_array(arg);
	}
	reset_std_stream(data->sh);
}

static void	handle_wait_signals(t_data *data, int exit_status)
{
	printf("\n");
	if (WIFSIGNALED(exit_status))
	{
		if (WTERMSIG(exit_status) == SIGINT)
			data->sh->exit_code = 130;
		else
			data->sh->exit_code = 131;
	}
	else
		data->sh->exit_code = -1;
}

void	launch_cmd(t_command *user_cmd, t_data *data)
{
	int		exit_status;
	char	*value;
	int		type;

	type = is_builtins(user_cmd);
	if (!user_cmd->next && user_cmd->args)
	{
		value = (char *)ft_lstlast(user_cmd->args)->content;
		update_env_var("_", ft_strdup(value), &data->sh->env, 3);
	}
	if (!user_cmd->next && (type == cd || type == exports || type == unset))
		handle_unexcd(user_cmd, data, type);
	else
	{
		fork_cmd_chain(user_cmd, data);
		set_signal(SIGINT, IGNORE);
		exit_status = wait_command(data);
		if (WIFEXITED(exit_status))
			data->sh->exit_code = WEXITSTATUS(exit_status);
		else
			handle_wait_signals(data, exit_status);
	}
}
