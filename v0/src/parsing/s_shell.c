/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_shell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 09:57:32 by nirirako@         #+#    #+#             */
/*   Updated: 2024/07/14 09:57:54 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_shell *new_shell(char **env)
{
	t_shell *sh;

	sh = (t_shell *)malloc(sizeof(t_shell));
	if (!sh)
		return (NULL);
	sh->env = NULL;
	sh->token = NULL;
	while (*env)
	{
		ft_lstadd_back(&sh->env, ft_lstnew(ft_strdup(*env)));
		env++;
	}
	sh->stdin = dup(STDIN_FILENO);
	sh->stdout = dup(STDOUT_FILENO);
	sh->path_lst = NULL;
	sh->exit_code = 0;
	return (sh);
}

void	destroy_shell(t_shell *sh)
{
	ft_lstclear(&sh->env, &free);
	if (sh->path_lst)
		free(sh->path_lst);
	close(sh->stdin);
	close(sh->stdout);
	destroy_token_chain(&sh->token);
	free(sh);
}

void	insert_env(t_shell *sh, char *var_env)
{
	ft_lstadd_back(&sh->env, ft_lstnew(ft_strdup(var_env)));
}

char	*ft_get_env(t_shell *sh, char *var_name)
{
	t_list	*env;
	char	*var;
	char	**tmp;

	env = sh->env;
	var = NULL;
	if (var_name[0] == '?')
		return (ft_itoa(sh->exit_code));
	while (env)
	{
		tmp = ft_split(env->content, '=');
		if (!ft_strncmp(tmp[0], var_name, ft_strlen(var_name)))
		{
			var = ft_strdup(env->content);
			free_str_array(tmp);
			tmp = ft_split(var, '=');
			free(var);
			var = ft_strdup(tmp[1]);
			free_str_array(tmp);
			break;
		}
		free_str_array(tmp);
		env = env->next;
	}
	return (var);
}

void remove_env(t_shell *sh, char *var_env)
{
	t_list	*env;
	t_list	*prev;
	char 	**tmp;

	prev = NULL;
	env = sh->env;
	while (env)
	{
		tmp = ft_split(env->content, '=');
		if (!ft_strncmp(tmp[0], var_env, ft_strlen(var_env)))
		{
			if (!prev)
				sh->env = env->next;
			else
				prev->next = env->next;
			ft_lstdelone(env, &free);
			free_str_array(tmp);
			break;
		}
		free_str_array(tmp);
		prev = env;
		env = env->next;
	}
}