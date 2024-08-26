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

int	is_builtins(t_command *cmd)
{
	int		r;
	char	*cmd_name;

	if (!cmd->args)
		return (0);
	cmd_name = (char *)cmd->args->content;
	if (ft_strlen(cmd_name) == 2 && !ft_strcmp(cmd_name, "cd"))
		r = cd;
	else if (ft_strlen(cmd_name) == 4 && !ft_strcmp(cmd_name, "exit"))
		r = exits;
	else if (ft_strlen(cmd_name) == 6 && !ft_strcmp(cmd_name, "export"))
		r = exports;
	else if (ft_strlen(cmd_name) == 5 && !ft_strcmp(cmd_name, "unset"))
		r = unset;
	else if (ft_strlen(cmd_name) == 3 && !ft_strcmp(cmd_name, "env"))
		r = env;
	else if (ft_strcmp(cmd_name, "pwd") == 0)
		r = pwd;
	else if (ft_strcmp(cmd_name, "echo") == 0)
		r = echo;
	else
		r = 0;
	return (r);
}

int	handle_builtins(char **arg, int type, t_shell *sh)
{
	int	r;

	if (type == cd)
		r = handle_cd(arg, sh);
	else if (type == env)
		r = handle_env(sh);
	else if (type == unset)
		r = handle_unset(sh, arg);
	else if (type == exports)
		r = handle_export(sh, arg);
	else if (type == exits)
		r = EXIT_SUCCESS;
	else if (type == pwd)
		r = handle_pwd();
	else if (type == echo)
		r = handle_echo (arg);
	else
		r = EXIT_SUCCESS;
	return (r);
}
