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

static int	print_export(t_env *env)
{
	while (env)
	{
		if (env->index == 3)
			printf("%s=%s\n", env->name, env->value);
		env = env->next;
	}
	return (EXIT_SUCCESS);
}

static int	check_var_name(char *var_name)
{
	if (!ft_isalpha(*var_name) && *var_name != '_')
		return (0);
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

	tmp = split_str(var);
	if (check_var_name(tmp[0]))
	{
		if (!set_env_var(tmp[0], tmp[1], sh->env))
			insert_2_env_lst(tmp[0], tmp[1], 3, &sh->env);
		exit_code = EXIT_SUCCESS;
	}
	else
	{
		report_error(tmp[0]);
		report_error(" : not a valid identifier\n");
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