/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_command.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 08:28:04 by nirirako@         #+#    #+#             */
/*   Updated: 2024/07/31 08:28:40 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef S_COMMAND_H
# define S_COMMAND_H
# include "s_stream.h"

typedef struct s_command
{
	t_stream	*io[2]; // io[0]: input io [1] output
	t_list	*args;
	struct s_command	*next;
}	t_command;

t_command	*new_command(void);
void		append_command(t_command **cmd, t_command *new);
void		insert_input(t_command *cmd, t_stream *input_stream);
void		insert_output(t_command *cmd, t_stream *output_stream);
void		insert_args(t_command *cmd, t_list *args);
void		destroy_command(t_command *cmd);
t_command	*last_command(t_command *cmd);
void		print_command(t_command *cmd);
void		print_args(t_list *args);
void		destroy_args(t_command *cmd);
#endif