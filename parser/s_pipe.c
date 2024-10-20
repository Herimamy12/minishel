/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_pipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:27:24 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/12 08:23:31 by nirirako         ###   ########.fr       */
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
	if (pipe(pipes->fds) < 0)
	{
		perror("pipe");
		free(pipes);
		pipes = NULL;
	}
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
	if (pipes)
	{
		close(pipes->fds[0]);
		dup2(pipes->fds[1], 1);
		close(pipes->fds[1]);
	}
}

void	set_pipe_2_input(t_pipe *pipes)
{
	if (pipes)
	{
		close(pipes->fds[1]);
		dup2(pipes->fds[0], 0);
		close(pipes->fds[0]);
	}
}
