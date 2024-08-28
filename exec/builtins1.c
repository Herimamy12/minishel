/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:24:29 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/21 13:24:38 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

#include "builtins.h"

static int	count_cd_arg(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
		i++;
	return (i);
}

static int	cd_error(char *dir)
{
	ft_putstr_fd(dir, 2);
	ft_putstr_fd(": too many arguments\n", 2);
	return (EXIT_FAILURE);
}

static char	*get_target_dir(t_shell *sh, char **cmd)
{
	char	*str;

	if (cmd[1] && cmd[1][0] == '-')
	{
		str = get_env_var_value(sh->env, "OLDPWD");
		if (!*str)
			report_error("cd: OLDPWD not set\n");
	}
	else if (!cmd[1])
	{
		str = get_env_var_value(sh->env, "HOME");
		if (!*str)
			report_error("cd: HOME not set\n");
	}
	else
		str = ft_strdup(cmd[1]);
	return (str);
}

int	handle_cd(char **cmd, t_shell *sh)
{
	int		exit_code;
	char	*target_dir;
	char	buf[1000];

	exit_code = EXIT_SUCCESS;
	getcwd(buf, 997);
	if (count_cd_arg(cmd) > 2)
		return (cd_error(cmd[0]));
	target_dir = get_target_dir(sh, cmd);
	if (chdir (target_dir) < 0)
	{
		if (*target_dir)
			perror(target_dir);
		exit_code = EXIT_FAILURE;
	}
	set_env_var("OLDPWD", ft_strdup(buf), sh->env);
	set_env_var("PWD", ft_strdup(cmd[1]), sh->env);
	free(target_dir);
	return (exit_code);
}
