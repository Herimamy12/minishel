/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:51:33 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/25 15:51:41 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	handle_env(t_shell *sh)
{
	print_env(sh->env);
	return (EXIT_SUCCESS);
}

int	handle_unset(t_shell *sh, char **tmp)
{
	int	i;

	i = 1;
	while (tmp[i])
	{
		remove_from_env_lst(tmp[i], &sh->env);
		i++;
	}
	return (EXIT_SUCCESS);
}
int	handle_pwd(void)
{
	char	buff[1000];

	getcwd(buff, 1000);
	printf("%s\n", buff);
	return (EXIT_SUCCESS);
}