/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stream.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 08:40:02 by nirirako@         #+#    #+#             */
/*   Updated: 2024/07/31 08:40:28 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STREAM_H
# define S_STREAM_H
# include "token.h"
# include "here_doc.h"

typedef struct s_stream
{
	enum e_token	type;
	void			*value;
	struct s_stream	*next;
}	t_stream;

t_stream	*new_stream(enum e_token type, char *fileName, t_shell *sh);
void		append_stream(t_stream **stream, t_stream *new);
void		destroy_stream(t_stream *stream);
void		print_stream(t_stream *stream);
t_stream	*last_stream(t_stream *stream);
#endif
