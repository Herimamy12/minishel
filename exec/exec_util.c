/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:24:52 by nherimam          #+#    #+#             */
/*   Updated: 2024/09/29 13:25:00 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	**get_path_lst(char **env)
{
	char	**str_path;
	char	**path;

	if (!env)
		return (NULL);
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

static char	*find_full_path(char *name, char **env)
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

static char	*get_path(char *name, char **env)
{
	char	**path_lst;
	char	*path;
	char	*tmp1;
	char	*tmp2;
	char	cwd[1000];

	path_lst = get_path_lst(env);
	if (!path_lst)
	{
		getcwd(cwd, 1000);
		tmp1 = ft_strjoin(cwd, "/");
		tmp2 = ft_strjoin(tmp1, name);
		if (access(tmp2, F_OK) == 0)
			path = ft_strdup(tmp2);
		else
			path = NULL;
		free(tmp1);
		free(tmp2);
	}
	else
		path = find_full_path(name, env);
	free_str_array(path_lst);
	return (path);
}

char	*find_cmd_path(char *name, char **env)
{
	char	*path;

	if (!*name || !ft_strcmp(name, ".") || !ft_strcmp(name, ".."))
		return (NULL);
	if (ft_strchr(name, '/'))
	{
		if (access(name, F_OK) == 0)
			return (ft_strdup(name));
		return (NULL);
	}
	path = get_path(name, env);
	return (path);
}
