/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:29:41 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/21 13:29:50 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	free_export_default(char **str)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		free (str[i]);
		i++;
	}
}

static int	print_export(t_env *env)
{
	t_env	*env_lst;
	t_env	*ptr;

	env_lst = dup_env_lst(env);
	ptr = env_lst;
	sort_env_lst(env_lst);
	while (env_lst)
	{
		if (ft_strcmp(env_lst->name, "_"))
		{
			printf("declare -x %s", env_lst->name);
			if (env_lst->value[0])
				printf("=\"%s\"", env_lst->value);
			printf("\n");
		}
		env_lst = env_lst->next;
	}
	destroy_env_lst(ptr);
	return (EXIT_SUCCESS);
}

static int	check_var_name(char *var_name)
{
	if (!ft_isalpha(*var_name) && *var_name != '_')
		return (0);
	var_name++;
	while (*var_name)
	{
		if (!ft_isalnum(*var_name) && *var_name != '_')
			return (0);
		var_name++;
	}
	return (1);
}

static int	ft_export(t_shell *sh, char *var)
{
	char	**tmp;
	int		exit_code;
	int		index;

	tmp = split_str(var);
	index = 3;
	if (check_var_name(tmp[0]))
	{
		if (!ft_strchr(var, '='))
			index = -1;
		if (!set_env_var(tmp[0], tmp[1], sh->env, index))
			insert_2_env_lst(tmp[0], tmp[1], index, &sh->env);
		else
			free (tmp[0]);
		exit_code = EXIT_SUCCESS;
	}
	else
	{
		report_error(tmp[0]);
		report_error(" : not a valid identifier\n");
		free_export_default (tmp);
		exit_code = EXIT_FAILURE;
	}
	free(tmp);
	return (exit_code);
}

int	handle_export(t_shell *sh, char	**var)
{
	int	i;
	int	exit_code;

	i = 1;
	if (!var[1])
		return (print_export(sh->env));
	while (var[i])
	{
		exit_code = ft_export(sh, var[i]);
		i++;
	}
	return (exit_code);
}
