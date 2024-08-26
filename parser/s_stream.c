/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stream.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 08:39:35 by nirirako@         #+#    #+#             */
/*   Updated: 2024/07/31 08:39:47 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stream.h"

t_stream	*new_stream(enum e_token type, char *fileName, t_shell *sh)
{
	t_stream	*stream;

	stream = (t_stream *)malloc(sizeof(t_stream));
	if (!stream)
	{
		printf("Malloc error\n");
		return (NULL);
	}
	stream->type = type;
	if (type != here_doc)
		stream->value = (char *)ft_strdup(fileName);
	else
		stream->value = new_here_doc(fileName, sh);
	stream->next = NULL;
	return (stream);
}

void	append_stream(t_stream **stream, t_stream *new)
{
	if (!*stream)
	{
		*stream = new;
		return ;
	}
	last_stream(*stream)->next = new;
}

void	destroy_stream(t_stream *stream)
{
	t_stream	*tmp;

	while (stream)
	{
		if (stream->type == here_doc)
			destroy_here_doc(stream->value);
		else
			free(stream->value);
		tmp = stream->next;
		free(stream);
		stream = tmp;
	}
}

void	print_stream(t_stream *stream)
{
	char	*str;

	if (!stream)
		printf("stdin / stdout\n");
	while (stream)
	{
		if (stream->type == input)
			str = "[input]";
		else if (stream->type == here_doc)
			str = "[here_doc]";
		else if (stream->type == output)
			str = "[output]";
		else
			str = "[append]";
		if (stream->type != here_doc)
			printf("%s %s\n", (char *)stream->value, str);
		else
			printf("%s\n", str);
		stream = stream->next;
	}
}

t_stream	*last_stream(t_stream *stream)
{
	if (!stream)
		return (stream);
	while (stream->next)
		stream = stream->next;
	return (stream);
}
