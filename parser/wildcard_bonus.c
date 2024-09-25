/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:21:06 by nirirako@         #+#    #+#             */
/*   Updated: 2024/09/19 12:21:16 by nirirako@        ###   ########.fr       */
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

	w = ft_split(wild, '/');
	file = NULL;
	find_match(".", w, &file, wild);
	free_temp_array(w);
	if (!file)
		file = new_file(wild, DIRECTORY, wild);
	return (file);
}
