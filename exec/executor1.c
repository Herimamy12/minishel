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
	t_stream	*input;
	t_here_doc	*hd;

	input = last_stream(cmd->io[0]);
	if (input && input->type == here_doc)
	{
		hd = (t_here_doc *)input->value;
		close_pipe(hd->hd_pipe);
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
	ft_lstclear(&lst, &free);
	exit(exit_code);
}
