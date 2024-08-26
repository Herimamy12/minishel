/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_stream.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:29:32 by nherimam          #+#    #+#             */
/*   Updated: 2024/08/02 10:29:33 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	handle_input(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (fd);
	dup2(fd, 0);
	close (fd);
	return (fd);
}

int	set_input_stream(t_stream *stream)
{
	t_here_doc	*hd;

	while (stream)
	{
		if (stream->type == here_doc && !stream->next)
		{
			hd = (t_here_doc *)stream->value;
			set_pipe_2_input(hd->hd_pipe);
		}
		else
		{
			if (stream->type != here_doc
				&& handle_input((char *)stream->value) < 0)
			{
				perror((char *)stream->value);
				return (0);
			}
		}
		stream = stream->next;
	}
	return (1);
}
