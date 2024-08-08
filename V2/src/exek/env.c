/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:46:32 by nherimam          #+#    #+#             */
/*   Updated: 2024/08/06 12:46:34 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	handle_env(t_shell *sh)
{
	t_list	*env;

	env = sh->env;
	while (env)
	{
		printf("%s\n", (char *)env->content);
		env = env->next;
	}
}

void	handle_unset(t_shell *sh, char **tmp)
{
	int	i;

	i = 1;
	while (tmp[i])
	{
		remove_env(sh, tmp[i]);
		i++;
	}
}

void	handle_export(t_shell *sh, char	**var)
{
	int	i;

	i = 1;
	while (var[i])
	{
		insert_env (sh, var[i]);
		i++;
	}
}
