/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:29:11 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/14 09:42:55 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard.h"

void	insert2leaf(t_file *f, t_file **leaf, char *wildcard)
{
	while (f)
	{
		if (wildcard[ft_strlen(wildcard) - 1] != '/')
			append_file(leaf, new_file(f->path_name, f->type, f->file_name));
		else
		{
			if (f->type == DIRECTORY)
				append_file(leaf, new_file(f->path_name, DIRECTORY,
						f->file_name));
		}
		f = f->next;
	}
}

void	find_match(char *dir, char **pattern, t_file **files, char *wildcard)
{
	t_file	*f;
	t_file	*p;
	char	*w;

	if (ft_strcmp(*pattern, "."))
		w = *pattern;
	else
		w = "*";
	pattern++;
	f = f_grep(dir, w);
	p = f;
	if (!*pattern)
	{
		insert2leaf(f, files, wildcard);
		destroy_file(f);
		return ;
	}
	while (f)
	{
		if (f->type == DIRECTORY)
			find_match(f->path_name, pattern, files, wildcard);
		f = f->next;
	}
	destroy_file(p);
}

void	free_temp_array(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

t_file	*wild_expand(char *wild)
{
	char	**w;
	t_file	*file;
	char	*path;

	w = ft_split(wild, '/');
	file = NULL;
	if (wild[0] == '/')
		path = "/";
	else if (!ft_strcmp(w[0], ".") || !ft_strcmp(w[0], ".."))
		path = w[0];
	else
		path = ".";
	find_match(path, w, &file, wild);
	free_temp_array(w);
	if (!file)
	{
		unescape_char(wild);
		file = new_file(wild, DIRECTORY, wild);
	}
	sort_file(file);
	return (file);
}
