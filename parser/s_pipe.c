/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_command_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:04:11 by nirirako@         #+#    #+#             */
/*   Updated: 2024/07/31 09:04:23 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_pipe.h"

t_pipe	*new_pipe(void)
{
	t_pipe	*pipes;

	pipes = (t_pipe *)malloc(sizeof(t_pipe));
	if (!pipes)
	{
		printf("Malloc error\n");
		return (NULL);
	}
	pipe(pipes->fds);
	return (pipes);
}

void	destroy_pipe(t_pipe *pipes)
{
	if (pipes)
	{
		close_pipe(pipes);
		free(pipes);
	}
}

void	close_pipe(t_pipe *pipes)
{
	if (pipes)
	{
		close(pipes->fds[0]);
		close(pipes->fds[1]);
	}
}

void	set_pipe_2_output(t_pipe *pipes)
{
	close(pipes->fds[0]);
	dup2(pipes->fds[1], 1);
	close(pipes->fds[1]);
}

void	set_pipe_2_input(t_pipe *pipes)
{
	close(pipes->fds[1]);
	dup2(pipes->fds[0], 0);
	close(pipes->fds[0]);
}
