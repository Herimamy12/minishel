/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:25:26 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/18 08:59:33 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readdir.h"

static void	read_dir(t_file **file, DIR *dir, char *root, int f)
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
		if (entry->d_name[0] != '.' || (entry->d_name[0] == '.' && f))
			append_file(file, new_file(path, type, entry->d_name));
		free(path);
	}
}

t_file	*ft_readdir(char *path, int f)
{
	DIR		*dir;
	t_file	*file;

	dir = opendir(path);
	file = NULL;
	if (!dir)
		return (NULL);
	read_dir(&file, dir, path, f);
	closedir(dir);
	return (file);
}

t_file	*f_grep(char *path, char *pattern)
{
	t_file	*file;
	t_file	*m;
	t_file	*p;

	file = ft_readdir(path, pattern[0] == '.');
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
