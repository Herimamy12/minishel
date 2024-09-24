/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_shell.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 09:54:05 by nirirako@         #+#    #+#             */
/*   Updated: 2024/07/14 09:54:34 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_SHELL_H
# define S_SHELL_H
# include "libft.h"
# include "s_token.h"
# include "s_env.h"

typedef struct s_shell
{
	t_env	*env;
	int		exit_code;
	int		stdin;
	int		stdout;
}	t_shell;

t_shell	*new_shell(char **env);
void	destroy_shell(t_shell *sh);
int		get_exit_code(t_shell *sh);
void	set_exit_code(t_shell *sh, int new_exit_code);
void	reset_std_stream(t_shell *sh);
#endif
