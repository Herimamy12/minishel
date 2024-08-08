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

#include "exek.h"

static int	handle_input(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (fd);
	dup2(fd, 0);
	close (fd);
	return (fd);
}

static void	read_stdin(char *stop_value, int out_fd)
{
	char	*line;

	line = "";
	while (1)
	{
		line = readline("here_doc> ");
		if (ft_strncmp(line, stop_value, ft_strlen(stop_value)) == 0)
			break ;
		ft_putstr_fd(line, out_fd);
		ft_putstr_fd("\n", out_fd);
		free(line);
	}
	close(out_fd);
}

static void	handle_here_doc(char *stop_value, t_data *data)
{
	int pipes[2];
	pid_t pid;

	pipe(pipes);
	pid = fork();
	if (pid == 0)
	{
		close(pipes[0]);
		read_stdin(stop_value, pipes[1]);
		destroy_data (data);
		exit (0);
	}
	else
		waitpid(pid, NULL, 0);
	close(pipes[1]);
	dup2(pipes[0], 0);
	close(pipes[0]);
}

int	set_input_stream(t_stream *stream, t_data *data)
{
	while (stream)
	{
		dup2(data->sh->stdin, 0);
		if (stream->type == here_doc)
			handle_here_doc((char *)stream->value, data);
		else
		{
			if (handle_input((char *)stream->value) < 0)
			{
				perror((char *)stream->value);
				return (0);
			}
		}
		stream = stream->next;
	}
	return (1);
}

