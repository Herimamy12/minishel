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
# include "token.h"

typedef struct s_shell
{
	t_list	*env;
	char	*path_lst;
	int		exit_code;
	int 	stdin;
	int 	stdout;
	t_token	*token;
}	t_shell;

t_shell *new_shell(char **env);
void	destroy_shell(t_shell *sh);
void	insert_env(t_shell *sh, char *var_env);
char	*ft_get_env(t_shell *sh, char *var_name);
void 	ft_remove_env(t_shell *sh, char *var_env);
#endif
