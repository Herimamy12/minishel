/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:06:32 by nirirako@         #+#    #+#             */
/*   Updated: 2024/09/19 10:06:42 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readdir.h"

static void	read_dir(t_file **file, DIR *dir, char *root)
{
	struct dirent	*entry;
	int				type;
	char			*path;

	while (1)
	{
		entry = readdir(dir);
		if (!entry)
			break ;
		if (entry->d_type == DT_DIR)
			type = DIRECTORY;
		else
			type = FILES;
		path = NULL;
		ft_append_str(&path, root);
		if (path[ft_strlen(path) - 1] != '/')
			ft_append_str(&path, "/");
		ft_append_str(&path, entry->d_name);
		if (entry->d_name[0] != '.')
			append_file(file, new_file(path, type, entry->d_name));
		free(path);
	}
}

t_file	*ft_readdir(char *path)
{
	DIR		*dir;
	t_file	*file;

	dir = opendir(path);
	file = NULL;
	if (!dir)
		return (NULL);
	read_dir(&file, dir, path);
	closedir(dir);
	return (file);
}

t_file	*f_grep(char *path, char *pattern)
{
	t_file	*file;
	t_file	*m;
	t_file	*p;

	file = ft_readdir(path);
	p = file;
	m = NULL;
	while (file)
	{
		if (match(file->file_name, pattern))
			append_file(&m, new_file(file->path_name, file->type,
					file->file_name));
		file = file->next;
	}
	destroy_file(p);
	return (m);
}
