/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:02:06 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/29 08:07:39 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parser.h"

int	main(int argc, char **argv, char **env)
{
	t_shell		*sh;
	t_token		*token;
	t_command	*cmd;

	if (!argc || !argv || !env)
		return (1);
	sh = new_shell(env);
	token = prompt_user(sh);
	cmd = parse_command(token);
	print_command(cmd);
	destroy_token(token);
	destroy_shell(sh);
	destroy_command(cmd);
	rl_clear_history();
	return (0);
}
