/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:58:15 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/08 09:58:49 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "parsing.h"
# include "s_shell.h"

enum {
	exits = -200,
	cd = -201,
	exports = -202,
	unset = -203,
	env = -204};

int is_builtins(t_command *cmd);
int handle_builtins(char **arg, int type, t_shell *sh);
int	handle_cd(char **cmd, t_shell *sh);
void	handle_env(t_shell *sh);
void	handle_unset(t_shell *sh, char **tmp);
void	handle_export(t_shell *sh, char	**var);

#endif
