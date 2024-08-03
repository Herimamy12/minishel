/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:28:05 by nirirako@         #+#    #+#             */
/*   Updated: 2024/07/30 08:28:41 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int main(int c, char **v, char **env)
{
	char	*str_cmd = "echo $? $HOME \"$HOME abc def\" > out";
	t_shell	*sh = new_shell(env);
	t_command	*cmd;	

	(void)c;
	(void)v;
	cmd = parse_command(str_cmd, sh);
	if (cmd)
	{
		print_command(cmd);
		destroy_command(cmd);
	}
	destroy_shell(sh);
	return (0);
}
