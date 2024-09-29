/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:23:07 by nherimam          #+#    #+#             */
/*   Updated: 2024/09/29 13:23:17 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "exec.h"

enum
{
	exits = -200,
	cd = -201,
	exports = -202,
	unset = -203,
	env = -204,
	pwd = -205,
	echo = -206
};

int		is_builtins(t_command *cmd);
int		handle_builtins(char **arg, int type, t_shell *sh);
int		handle_cd(char **cmd, t_shell *sh);
int		handle_env(t_shell *sh);
int		handle_unset(t_shell *sh, char **tmp);
int		handle_export(t_shell *sh, char	**var);
int		handle_pwd(void);
int		handle_echo(char **av);
void	handle_exit(t_data *data);
#endif
