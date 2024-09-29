/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako < nirirako@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:26:29 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 14:01:43 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_env.h"
#include "utility.h"

t_env	*new_env(char *var_name, char *var_value, int index)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
	{
		report_error("Malloc error in new_env\n");
		return (NULL);
	}
	env->name = var_name;
	env->value = var_value;
	env->index = index;
	env->next = NULL;
	return (env);
}

t_env	*new_env_lst(char **env)
{
	char	**tmp;
	int		index;
	t_env	*s_env;

	index = 0;
	s_env = NULL;
	if (!env)
		return (NULL);
	while (env[index])
	{
		tmp = split_str(env[index]);
		insert_2_env_lst(tmp[0], tmp[1], 0, &s_env);
		free(tmp);
		index++;
	}
	return (s_env);
}

t_env	*last_env(t_env *env)
{
	while (env && env->next)
		env = env->next;
	return (env);
}

void	insert_2_env_lst(char *var_name, char *var_value,
	int index, t_env **env)
{
	if (!*env)
	{
		*env = new_env(var_name, var_value, index);
		return ;
	}
	last_env(*env)->next = new_env(var_name, var_value, index);
}

void	destroy_env(t_env *env)
{
	free(env->name);
	free(env->value);
	free(env);
}
