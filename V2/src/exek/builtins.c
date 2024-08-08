/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:40:58 by nherimam          #+#    #+#             */
/*   Updated: 2024/08/03 15:41:00 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int is_builtins(t_command *cmd)
{
	int r;
	char	*cmd_name;

	cmd_name = (char *)cmd->args->content;
	if (ft_strlen(cmd_name) == 2 && !ft_strncmp(cmd_name, "cd", 2))
		r = cd;
	else if (ft_strlen(cmd_name) == 4 && !ft_strncmp(cmd_name, "exit", 4))
		r = exits;
	else if (ft_strlen(cmd_name) == 6 && !ft_strncmp(cmd_name, "export", 6))
		r = exports;
	else if (ft_strlen(cmd_name) == 5 && !ft_strncmp(cmd_name, "unset", 5))
		r = unset;
	else if (ft_strlen(cmd_name) == 3 && !ft_strncmp(cmd_name, "env", 3))
		r = env;
	else
		r = 0;
	return (r);
}

int handle_builtins(char **arg, int type, t_shell *sh)
{
	int r;

	if (type == cd)
		r = handle_cd(arg, sh);
	else if (type == env)
		handle_env(sh);
	else if (type == unset)
		handle_unset(sh, arg);
	else if (type == exports)
		handle_export(sh, arg);
	else if (type == exits)
		r = EXIT_SUCCESS;
	else
		r = EXIT_SUCCESS;
	return (r);
}
