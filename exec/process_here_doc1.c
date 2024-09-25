/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_here_doc1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:13:21 by nirirako@         #+#    #+#             */
/*   Updated: 2024/09/10 16:13:28 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static t_data	*data_handler(t_data *data)
{
	static t_data	*data_var = NULL;

	if (data)
		data_var = data;
	return (data_var);
}

static void	here_doc_sig_handler(int signum)
{
	t_data	*data;

	if (signum != SIGINT)
		return ;
	data = data_handler(NULL);
	destroy_data(data);
	rl_clear_history();
	exit(130);
}

int	get_here_doc(t_here_doc *hd, t_data *data)
{
	int	pid;
	int	exit_status;

	pid = fork();
	if (pid == 0)
	{
		data_handler(data);
		signal(SIGINT, &here_doc_sig_handler);
		close(hd->pipe->fds[0]);
		handle_here_doc(hd->lim, data->sh, hd->pipe->fds[1], hd->expand);
		destroy_data(data);
		exit(EXIT_SUCCESS);
	}
	set_signal(SIGINT, IGNORE);
	waitpid(pid, &exit_status, 0);
	if (WIFEXITED(exit_status) && WEXITSTATUS(exit_status) != 130)
		return (WEXITSTATUS(exit_status));
	printf("\n");
	return (130);
}
