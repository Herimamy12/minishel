/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:49:18 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/24 10:58:25 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(char **env, int *exit_code)
{
	t_shell	*sh;
	t_data	*data;

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
	*exit_code = sh->exit_code;
	destroy_shell(sh);
	free(data);
}

int	main(int argc, char **argv, char **env)
{
	int	exit_code;

	if (!argc || !argv || !env)
		return (1);
	minishell(env, &exit_code);
	return (exit_code);
}
