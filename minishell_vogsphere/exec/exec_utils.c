/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:48:57 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/29 07:59:08 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	pre_execve(char *cmd_path, char **str_cmd)
{
	if (!cmd_path)
	{
		report_error(str_cmd[0]);
		if (ft_strchr(str_cmd[0], '/'))
			report_error(" : No such file or directory\n");
		else
			report_error(" : command not found\n");
		return (127);
	}
	if ((!access(cmd_path, F_OK) && access(cmd_path, X_OK) != 0)
		|| is_a_directory(*str_cmd))
	{
		report_error(str_cmd[0]);
		if (!is_a_directory(*str_cmd))
			report_error(" : Permission denied\n");
		else
			report_error(" : Is a directory\n");
		return (126);
	}
	return (0);
}

int	ft_execvpe(char **str_cmd, char **env)
{
	char	*cmd_path;
	int		r;

	if (!str_cmd)
		return (EXIT_SUCCESS);
	if (ft_strchr(str_cmd[0], '/') && is_a_directory(*str_cmd))
	{
		report_error(*str_cmd);
		report_error(": Is a directory\n");
		return (126);
	}
	cmd_path = find_cmd_path(str_cmd[0], env);
	r = pre_execve(cmd_path, str_cmd);
	if (r != 0)
	{
		if (cmd_path)
			free(cmd_path);
		return (r);
	}
	execve(cmd_path, str_cmd, env);
	perror(str_cmd[0]);
	free(cmd_path);
	return (EXIT_FAILURE);
}
