/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_env3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:26:48 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/12 08:23:25 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_env.h"
#include "utility.h"
#include "libft.h"

int	does_env_var_exist(char *var_name, t_env *env)
{
	while (env)
	{
		if (!ft_strcmp(var_name, env->name))
			return (1);
		env = env->next;
	}
	return (0);
}

int	get_index(char *var_name, t_env *env)
{
	while (env)
	{
		if (!ft_strcmp(var_name, env->name))
			return (env->index);
		env = env->next;
	}
	return (5);
}

void	set_index(char *var_name, t_env *env, int index)
{
	while (env)
	{
		if (!ft_strcmp(var_name, env->name))
		{
			env->index = index;
			break ;
		}
		env = env->next;
	}
}

int	set_env_var(char *var_name, char *new_value, t_env *env, int index)
{
	if (index == -1 && does_env_var_exist(var_name, env))
	{
		if (!ft_strcmp("OLDPWD", var_name) || !ft_strcmp("PWD", var_name))
			set_index(var_name, env, 3);
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
