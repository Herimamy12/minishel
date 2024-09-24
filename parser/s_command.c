/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:45:39 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/27 08:48:02 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_command.h"

t_command	*new_command(void)
{
	t_command	*cmd;

	cmd = (t_command *)malloc(sizeof(t_command));
	if (!cmd)
	{
		printf("Malloc error\n");
		return (NULL);
	}
	cmd->stream = NULL;
	cmd->args = NULL;
	cmd->next = NULL;
	cmd->prev = NULL;
	cmd->pipes = NULL;
	cmd->pid = -1;
	return (cmd);
}

t_command	*last_command(t_command *cmd)
{
	if (!cmd)
		return (cmd);
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
}

int	append_command(t_command **cmd, t_command *new)
{
	t_command	*last;
	t_pipe		*p;

	if (!*cmd)
	{
		*cmd = new;
		return (1);
	}
	p = new_pipe();
	last = last_command(*cmd);
	if (p)
		last->pipes = p;
	else
		last->pipes = NULL;
	last->next = new;
	new->prev = last;
	return (!(p == NULL));
}

void	destroy_command(t_command *cmd)
{
	t_command	*tmp;

	while (cmd)
	{
		tmp = cmd->next;
		destroy_stream(cmd->stream);
		destroy_args(cmd);
		destroy_pipe(cmd->pipes);
		free(cmd);
		cmd = tmp;
	}
}

void	print_args(t_list *args)
{
	while (args)
	{
		printf("%s ", (char *)args->content);
		args = args->next;
	}
	printf("\n");
}
