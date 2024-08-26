/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:02:06 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/19 09:02:22 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	main(int argc, char **argv, char **env)
{
	char		*cmd;
	t_token		*token;
	t_shell		*sh;
	t_command	*str_cmd;

	if (!argc || !argv || !env)
		return (1);
	cmd = "cmd1|cmd2";
	sh = new_shell(env);
	token = cmd_parser(cmd, sh);
	print_token(token);
	if (token)
	{
		str_cmd = cmd_builder(token, sh);
		print_command (str_cmd);
		destroy_command(str_cmd);
		destroy_token(token);
	}
	destroy_shell(sh);
	return (0);
}
