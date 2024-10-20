/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_shell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:27:30 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/12 08:23:33 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_shell.h"
#include "utility.h"

t_shell	*new_shell(char **env)
{
	t_shell	*sh;

	sh = (t_shell *)malloc(sizeof(t_shell));
	if (!sh)
		return (NULL);
	sh->env = new_env_lst(env);
	sh->stdin = dup(0);
	sh->stdout = dup(1);
	sh->exit_code = 0;
	return (sh);
}

void	destroy_shell(t_shell *sh)
{
	close(sh->stdin);
	close(sh->stdout);
	destroy_env_lst(sh->env);
	free(sh);
}

int	get_exit_code(t_shell *sh)
{
	return (sh->exit_code);
}

void	set_exit_code(t_shell *sh, int new_exit_code)
{
	sh->exit_code = new_exit_code;
}

void	reset_std_stream(t_shell *sh)
{
	dup2(sh->stdout, 1);
	dup2(sh->stdin, 0);
}
