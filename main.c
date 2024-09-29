/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:32:43 by nherimam          #+#    #+#             */
/*   Updated: 2024/09/29 13:32:45 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_shell_level(t_shell *sh)
{
	char	*shlvl;
	int		num_shlvl;

	shlvl = get_env_var_value(sh->env, "SHLVL");
	num_shlvl = ft_atoi(shlvl) + 1;
	update_env_var("SHLVL", ft_itoa(num_shlvl), &sh->env, 3);
	free(shlvl);
}

void	minishell(char **env, int *exit_code)
{
	t_shell	*sh;
	t_data	*data;

	sh = new_shell(env);
	update_shell_level(sh);
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
