/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_command1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:26:24 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/14 11:20:54 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_command.h"

void	insert_stream(t_command *cmd, t_stream *stream)
{
	append_stream(&cmd->stream, stream);
}

void	insert_args(t_command *cmd, t_list *args)
{
	ft_lstadd_back(&cmd->args, args);
}

void	print_command(t_command *cmd)
{
	printf("(");
	while (cmd)
	{
		print_args(cmd->args);
		if (cmd->next)
			printf(" | ");
		cmd = cmd->next;
	}
	printf(")");
}

void	destroy_args(t_command *cmd)
{
	t_list	*lst;

	while (cmd->args)
	{
		lst = cmd->args;
		cmd->args = cmd->args->next;
		free(lst->content);
		free(lst);
	}
}
