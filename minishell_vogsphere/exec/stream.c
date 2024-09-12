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
	{
		perror(file_name);
		return (fd);
	}
	dup2(fd, 0);
	close (fd);
	return (fd);
}

static int	handle_output(char *file_name)
{
	int	fd;

	fd = open (file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file_name);
		return (fd);
	}
	dup2(fd, 1);
	close(fd);
	return (fd);
}

static int	handle_append(char *file_name)
{
	int	fd;

	fd = open (file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		perror(file_name);
		return (fd);
	}
	dup2(fd, 1);
	close(fd);
	return (fd);
}

int	set_io_stream(t_command *cmd)
{
	t_stream	*stream;
	char		*file_name;
	int			r;

	stream = cmd->stream;
	while (stream)
	{
		r = 1;
		if (stream->type != here_doc)
			file_name = (char *)stream->value;
		if (stream->type == input && handle_input(file_name) < 0)
			r = 0;
		else if (stream->type == output && handle_output(file_name) < 0)
			r = 0;
		else if (stream->type == append && handle_append(file_name) < 0)
			r = 0;
		else if (stream->type == here_doc)
			set_pipe_2_input(((t_here_doc *)stream->value)->pipe);
		if (!r)
			return (0);
		stream = stream->next;
	}
	return (1);
}
