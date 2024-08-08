/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:09:11 by nherimam          #+#    #+#             */
/*   Updated: 2024/08/02 13:09:11 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	count_cd_arg(char **cmd)
{
	int i;

	i = 0;
	while (cmd[i] != NULL)
		i++;
	return (i);
}

int cd_error(char *dir)
{
	ft_putstr_fd(dir, 2);
	ft_putstr_fd(": too many arguments\n", 2);
	return (127);
}

char	*get_target_dir(t_shell *sh, char **cmd)
{
	char	*str;

	if (cmd[1] && cmd[1][0] == '-')
		str = ft_get_env(sh, "OLDPWD");
	else if (!cmd[1])
		str = ft_get_env(sh, "HOME");
	else
		str = ft_strdup(cmd[1]);
	return (str);
}

int	handle_cd(char **cmd, t_shell *sh)
{
	int		exit_code;
	char	*target_dir;
	char	*tmp;
	char	buf[1000];

	exit_code = EXIT_SUCCESS;
	getcwd(buf, 997);
	if (count_cd_arg(cmd) > 2)
		return (cd_error(cmd[0]));
	target_dir = get_target_dir(sh, cmd);
	if (!(chdir (target_dir) != 0))
	{
		remove_env(sh, "OLDPWD");
		tmp = ft_strjoin("OLDPWD=", buf);
		insert_env(sh, tmp);
		free(tmp);
	}
	free(target_dir);
	return (exit_code);
}
