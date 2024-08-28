/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:48:57 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/28 12:49:05 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	is_str_empty(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i][0])
			return (0);
		i++;
	}
	return (1);
}

static int	pre_execve(char *cmd_path, char **str_cmd)
{
	if (!cmd_path)
	{
		report_error(str_cmd[0]);
		report_error(" : command not found\n");
		return (127);
	}
	if (access(cmd_path, X_OK) != 0)
	{
		report_error(str_cmd[0]);
		report_error(" : Permission denied\n");
		return (126);
	}
	return (0);
}

int	ft_execvpe(char **str_cmd, char **env)
{
	char	*cmd_path;
	int		r;

	if (!str_cmd || is_str_empty(str_cmd))
		exit(EXIT_SUCCESS);
	if (is_a_directory(*str_cmd))
	{
		report_error(*str_cmd);
		report_error(": Is a directory\n");
		return (126);
	}
	cmd_path = find_cmd_path(str_cmd[0], env);
	r = pre_execve(cmd_path, str_cmd);
	if (r != 0)
		return (r);
	execve(cmd_path, str_cmd, env);
	perror(str_cmd[0]);
	free(cmd_path);
	return (EXIT_FAILURE);
}
