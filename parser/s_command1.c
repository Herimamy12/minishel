/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_command1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:26:24 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/12 08:23:17 by nirirako         ###   ########.fr       */
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
	int	i;

	i = 1;
	while (cmd)
	{
		printf("\tCommand %d\n", i);
		printf("# STREAM\n");
		print_stream(cmd->stream);
		printf("# ARGS\n");
		print_args(cmd->args);
		cmd = cmd->next;
		i++;
	}
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
