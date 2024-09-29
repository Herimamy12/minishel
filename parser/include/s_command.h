/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_command.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:31:30 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 13:31:33 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_COMMAND_H
# define S_COMMAND_H
# include "s_stream.h"
# include "s_pipe.h"
# include "s_token.h"
# include "s_shell.h"

typedef struct s_command
{
	t_stream			*stream;
	t_list				*args;
	t_pipe				*pipes;
	int					pid;
	struct s_command	*next;
	struct s_command	*prev;
}	t_command;

t_command	*new_command(void);
t_command	*last_command(t_command *cmd);
int			append_command(t_command **cmd, t_command *new);
void		insert_stream(t_command *cmd, t_stream *stream);
void		insert_args(t_command *cmd, t_list *args);
void		destroy_command(t_command *cmd);
void		print_command(t_command *cmd);
void		print_args(t_list *args);
void		destroy_args(t_command *cmd);
#endif
