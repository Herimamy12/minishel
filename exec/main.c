/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:49:18 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/21 11:50:00 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	main(int argc, char **argv, char **env)
{
	char		*s_cmd;
	t_shell		*sh;
	t_command	*cmd;
	t_data		*data;
	t_token		*token;

	if (!argc || !argv || !env)
		return (1);
	s_cmd = "< main.c << eof < exit.c cat -e";
	sh = new_shell(env);
	token = cmd_parser(s_cmd, sh);
	cmd = cmd_builder(token, sh);
	data = new_data(cmd, sh);
	if (cmd)
		launch_cmd(cmd, data);
	print_command (cmd);
	destroy_token(token);
	destroy_data(data);
	return (0);
}
