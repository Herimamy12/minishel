/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stream.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:27:39 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/12 08:23:35 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stream.h"
#include "utility.h"

t_stream	*new_stream(enum e_token type, void *value)
{
	t_stream	*stream;
	char		*str;

	stream = (t_stream *)malloc(sizeof(t_stream));
	if (!stream)
	{
		report_error("Malloc error in t_stream\n");
		return (NULL);
	}
	str = (char *)value;
	stream->type = type;
	stream->next = NULL;
	if (type != here_doc)
		stream->value = ft_strdup(value);
	else
		stream->value = new_here_doc(str);
	return (stream);
}

t_stream	*last_stream(t_stream *stream)
{
	while (stream && stream->next)
		stream = stream->next;
	return (stream);
}

void	append_stream(t_stream **stream, t_stream *n_stream)
{
	if (!*stream)
	{
		*stream = n_stream;
		return ;
	}
	last_stream(*stream)->next = n_stream;
}

void	destroy_stream(t_stream *stream)
{
	t_stream	*tmp;

	while (stream)
	{
		tmp = stream;
		stream = stream->next;
		if (tmp->type == here_doc)
			destroy_here_doc((t_here_doc *)tmp->value);
		else
			free((char *)tmp->value);
		free(tmp);
	}
}

void	print_stream(t_stream *stream)
{
	while (stream)
	{
		if (stream->type != here_doc)
			printf("[%s : %s]\n", print_token_type(stream->type),
				(char *)stream->value);
		else
			print_here_doc((t_here_doc *)stream->value);
		stream = stream->next;
	}
}
