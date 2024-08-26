/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_stream.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:55:39 by nherimam          #+#    #+#             */
/*   Updated: 2024/08/02 10:55:49 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	handle_output(char *file_name)
{
	int	fd;

	fd = open (file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (fd);
	dup2(fd, 1);
	close(fd);
	return (fd);
}

static int	handle_append(char *file_name)
{
	int	fd;

	fd = open (file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		return (fd);
	dup2(fd, 1);
	close(fd);
	return (fd);
}

int	set_output_stream(t_stream *stream, t_data *data)
{
	int	r;

	while (stream)
	{
		dup2(data->sh->stdout, 1);
		if (stream->type == append)
			r = handle_append ((char *)stream->value);
		else
			r = handle_output ((char *)stream->value);
		if (r < 0)
		{
			perror((char *)stream->value);
			return (0);
		}
		stream = stream->next;
	}
	return (1);
}
