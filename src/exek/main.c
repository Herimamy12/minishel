/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:46:23 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/01 09:46:25 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exek.h"

void	ft_exec(t_shell *sh, t_command *cmd)
{
	char	**str_cmd;
	char	**str_env;
	pid_t	pid;

	str_env = lst_2_str(sh->env);
	while (cmd)
	{
		str_cmd = lst_2_str(cmd->args);
		pid = fork();
		if (pid == 0)
		{
			execvp(str_cmd[0], str_cmd);
			perror("execvpe");	
		}
		else
			wait(NULL);
		free_str_array(str_cmd);
		cmd = cmd->next;
	}
	free_str_array(str_env);
}

int main(int c, char **v, char **env)
{
	t_command	*cmd;
	char	*s_cmd = "echo \"$?abc def abc\"";
	t_shell	*sh;

	(void)c;
	(void)v;
	sh = new_shell(env);
	cmd = parse_command(s_cmd, sh);
	if (cmd)
	{
		ft_exec(sh, cmd);
		destroy_command(cmd);
	}
	destroy_shell(sh);
	return (0);
}
