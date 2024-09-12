/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_env1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:09:28 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/21 09:09:36 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_env.h"
#include "utility.h"

void	remove_from_env_lst(char *var_name, t_env **env)
{
	t_env	*tmp;
	t_env	*temp;

	tmp = *env;
	if (!*env)
		return ;
	if (!ft_strcmp((*env)->name, var_name))
	{
		*env = (*env)->next;
		destroy_env(tmp);
		return ;
	}
	while (tmp)
	{
		if (tmp->next && !ft_strcmp(tmp->next->name, var_name))
		{
			temp = tmp->next;
			tmp->next = temp->next;
			destroy_env(temp);
			break ;
		}
		tmp = tmp->next;
	}
}

void	destroy_env_lst(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		destroy_env(tmp);
	}
}

char	*get_env_var_value(t_env *env, char *var_name)
{
	while (env)
	{
		if (!ft_strcmp(var_name, env->name))
			return (ft_strdup(env->value));
		env = env->next;
	}
	return (ft_strdup(""));
}

void	print_env(t_env *env)
{
	while (env)
	{
		if (env->index >= 0)
			printf("%s=%s\n", env->name, env->value);
		env = env->next;
	}
}
