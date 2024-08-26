/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_command_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:04:27 by nirirako@         #+#    #+#             */
/*   Updated: 2024/07/31 09:04:38 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_command.h"

void	insert_input(t_command *cmd, t_stream *input_stream)
{
	append_stream(&cmd->io[0], input_stream);
}

void	insert_output(t_command *cmd, t_stream *output_stream)
{
	append_stream(&cmd->io[1], output_stream);
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
		printf("# INPUT\n");
		print_stream(cmd->io[0]);
		printf("# OUTPUT\n");
		print_stream(cmd->io[1]);
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
