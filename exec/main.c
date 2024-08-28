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
	t_shell	*sh;
	t_data	*data;

	if (!argc || !argv || !env)
		return (1);
	sh = new_shell(env);
	data = new_data(NULL, sh);
	while (1)
	{
		set_signal(SIGINT, HANDLER);
		set_signal(SIGQUIT, IGNORE);
		if (!cmd_executor(data))
			break ;
	}
	rl_clear_history();
	destroy_data(data);
	return (0);
}
