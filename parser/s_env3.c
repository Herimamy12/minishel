/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_env2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:10:00 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/21 09:10:08 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_env.h"
#include "utility.h"
#include "libft.h"

static int	does_env_var_exist(char *var_name, t_env *env)
{
	while (env)
	{
		if (!ft_strcmp(var_name, env->name))
			return (1);
		env = env->next;
	}
	return (0);
}

int	set_env_var(char *var_name, char *new_value, t_env *env, int index)
{
	if (index == -1 && does_env_var_exist(var_name, env))
	{
		free(new_value);
		return (1);
	}
	while (env)
	{
		if (!ft_strcmp(var_name, env->name))
		{
			free(env->value);
			env->value = new_value;
			env->index = index;
			return (1);
		}
		env = env->next;
	}
	return (0);
}

void	update_env_var(char *var_name, char *new_value, t_env **env, int index)
{
	if (does_env_var_exist(var_name, *env))
		set_env_var(var_name, new_value, *env, index);
	else
		insert_2_env_lst(ft_strdup(var_name), new_value, index, env);
}
