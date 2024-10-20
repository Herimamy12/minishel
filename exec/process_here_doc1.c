/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_here_doc1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:27:09 by nherimam          #+#    #+#             */
/*   Updated: 2024/10/19 15:29:33 by nirirako         ###   ########.fr       */
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
		close(hd->pipe->fds[1]);
		destroy_data(data);
		rl_clear_history();
		exit(EXIT_SUCCESS);
	}
	set_signal(SIGINT, IGNORE);
	waitpid(pid, &exit_status, 0);
	if (WIFEXITED(exit_status) && WEXITSTATUS(exit_status) != 130)
		return (WEXITSTATUS(exit_status));
	printf("\n");
	return (130);
}
