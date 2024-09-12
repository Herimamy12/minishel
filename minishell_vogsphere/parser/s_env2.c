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

t_list	*env_2_lst(t_env *env)
{
	t_list	*lst;
	char	*tmp0;
	char	*tmp1;

	lst = NULL;
	while (env)
	{
		tmp0 = ft_strjoin(env->name, "=");
		tmp1 = ft_strjoin(tmp0, env->value);
		free(tmp0);
		ft_lstadd_back(&lst, ft_lstnew(tmp1));
		env = env->next;
	}
	return (lst);
}

int	set_env_var(char *var_name, char *new_value, t_env *env, int index)
{
	if (index == -1)
		return (1);
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

t_env	*dup_env_lst(t_env *env_lst)
{
	t_env	*env;

	env = NULL;
	while (env_lst)
	{
		insert_2_env_lst(ft_strdup(env_lst->name),
			ft_strdup(env_lst->value), 3, &env);
		env_lst = env_lst->next;
	}
	return (env);
}

void	swap_env_lst_items(t_env *env1, t_env *env2)
{
	char	*tmp_name;
	char	*tmp_value;
	int		tmp_index;

	tmp_name = env1->name;
	tmp_value = env1->value;
	tmp_index = env1->index;
	env1->name = env2->name;
	env1->value = env2->value;
	env1->index = env2->index;
	env2->name = tmp_name;
	env2->value = tmp_value;
	env2->index = tmp_index;
}

void	sort_env_lst(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		while (tmp)
		{
			if (ft_strcmp(env->name, tmp->name) > 0)
				swap_env_lst_items(env, tmp);
			else
				tmp = tmp->next;
		}
		env = env->next;
	}
}
