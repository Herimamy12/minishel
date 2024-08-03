/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_command_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:04:11 by nirirako@         #+#    #+#             */
/*   Updated: 2024/07/31 09:04:23 by nirirako@        ###   ########.fr       */
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
	cmd->io[0] = NULL;
	cmd->io[1] = NULL;
	cmd->args = NULL;
	cmd->next = NULL;
	return (cmd);
}

void	append_command(t_command **cmd, t_command *new)
{
	if (!*cmd)
	{
		*cmd = new;
		return ;
	}
	last_command(*cmd)->next = new;
}

void	destroy_command(t_command *cmd)
{
	t_command	*tmp;

	while (cmd)
	{
		tmp = cmd->next;
		destroy_stream(cmd->io[0]);
		destroy_stream(cmd->io[1]);
		destroy_args(cmd);
		free(cmd);
		cmd = tmp;
	}
}

t_command	*last_command(t_command *cmd)
{
	if (!cmd)
		return (cmd);
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
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