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

t_token	*prompt_user(t_shell *sh)
{
	t_token	*token;
	t_token	*r_token;
	char	*line;
	char	*prompt;

	r_token = NULL;
	prompt = "minishell> ";
	set_signal(SIGINT, HANDLER);
	set_signal(SIGQUIT, IGNORE);
	while (1)
	{
		line = readline(prompt);
		if (!line)
			return (NULL);
		add_history (line);
		token = cmd_parser(line, sh);
		free(line);
		if (token)
		{
			append_token(&r_token, token);
			prompt = "> ";
			if (last_token(token)->type != pipes)
				break ;
		}
	}
	return (r_token);
}

int	handle_main_loop(t_shell *sh, t_data *data)
{
	t_token		*token;
	t_command	*cmd;

	token = prompt_user(sh);
	if (token)
	{
		cmd = cmd_builder(token, sh);
		data->cmd = cmd;
		if (data->cmd->args && !data->cmd->next && !ft_strcmp(
				data->cmd->args->content, "exit"))
			handle_exit (data);
		else
			launch_cmd(cmd, data);
		destroy_token(token);
		destroy_command(cmd);
		return (1);
	}
	return (0);
}

void	minishell(char **env, int *exit_code)
{
	t_shell	*sh;
	t_data	*data;

	sh = new_shell(env);
	data = new_data(NULL, sh);
	while (1)
	{
		if (!handle_main_loop(sh, data))
			break ;
	}
	*exit_code = data->sh->exit_code;
	destroy_shell(sh);
	free(data);
}

int	main(int argc, char **argv, char **env)
{
	int	exit_code;

	if (!argc || !argv || !env)
		return (1);
	minishell(env, &exit_code);
	rl_clear_history ();
	return (exit_code);
}
