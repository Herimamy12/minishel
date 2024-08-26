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

int	set_env_var(char *var_name, char *new_value, t_env *env)
{
	while (env)
	{
		if (!ft_strcmp(var_name, env->name))
		{
			free(env->value);
			env->value = new_value;
			return (1);
		}
		env = env->next;
	}
	return (0);
}
