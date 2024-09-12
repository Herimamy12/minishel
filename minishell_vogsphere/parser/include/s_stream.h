/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stream.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:04:00 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/27 08:51:40 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STREAM_H
# define S_STREAM_H
# include "s_token.h"
# include "s_here_doc.h"

typedef struct s_stream
{
	enum e_token	type;
	void			*value;
	struct s_stream	*next;
}	t_stream;
t_stream	*new_stream(enum e_token type, void *value);
t_stream	*last_stream(t_stream *stream);
void		append_stream(t_stream **stream, t_stream *n_stream);
void		destroy_stream(t_stream *stream);
void		print_stream(t_stream *stream);
#endif
