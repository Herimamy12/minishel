/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:24:06 by nherimam          #+#    #+#             */
/*   Updated: 2024/09/29 13:24:13 by nherimam         ###   ########.fr       */
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
			report_error("cd: $OLDPWD not set\n");
	}
	else if (!cmd[1])
	{
		str = get_env_var_value(sh->env, "HOME");
		if (!*str)
			report_error("cd: $HOME not set\n");
	}
	else
		str = ft_strdup(cmd[1]);
	return (str);
}

int	handle_cd(char **cmd, t_shell *sh)
{
	char	*target_dir;
	char	buf[1000];
	char	*tmp;

	getcwd(buf, 997);
	if (count_cd_arg(cmd) > 2)
		return (cd_error(cmd[0]));
	target_dir = get_target_dir(sh, cmd);
	if (chdir (target_dir) < 0)
	{
		if (*target_dir)
			perror(target_dir);
		free(target_dir);
		return (EXIT_FAILURE);
	}
	tmp = ft_strdup(buf);
	if (does_env_var_exist("PWD", sh->env))
		update_env_var("OLDPWD", tmp, &sh->env, 3);
	else
		free(tmp);
	getcwd(buf, 997);
	tmp = ft_strdup(buf);
	update_env_var("PWD", tmp, &sh->env, 3);
	free(target_dir);
	return (EXIT_SUCCESS);
}
