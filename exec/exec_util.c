/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:34:04 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/24 08:58:25 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	**get_path_lst(char **env)
{
	char	**str_path;
	char	**path;

	while (*env)
	{
		if (ft_strnstr(*env, "PATH", ft_strlen("PATH")))
			break ;
		env++;
	}
	if (!*env)
		return (NULL);
	str_path = ft_split(*env, '=');
	path = ft_split(str_path[1], ':');
	free_str_array(str_path);
	return (path);
}

char	*find_full_path(char *name, char **env)
{
	char	*path_name;
	char	*full_cmd;
	char	**path_lst;
	char	**ptr;

	path_lst = get_path_lst(env);
	if (!path_lst)
		return (NULL);
	ptr = path_lst;
	while (*path_lst)
	{
		path_name = ft_strjoin("/", name);
		full_cmd = ft_strjoin(*path_lst, path_name);
		if (access(full_cmd, X_OK) == 0)
		{
			free(path_name);
			free_str_array(ptr);
			return (full_cmd);
		}
		path_lst++;
		free(path_name);
		free(full_cmd);
	}
	free_str_array(ptr);
	return (NULL);
}

char	*find_cmd_path(char *name, char **env)
{
	if (ft_strchr(name, '/'))
		return (ft_strdup(name));
	return (find_full_path(name, env));
}
