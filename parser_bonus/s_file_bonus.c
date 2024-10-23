/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_file_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:26:53 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/12 08:23:28 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_file.h"
#include "utility.h"

t_file	*new_file(char *path_name, int type, char *file_name)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
	{
		report_error("Malloc error on t_file\n");
		return (NULL);
	}
	file->next = NULL;
	file->path_name = ft_strdup(path_name);
	file->type = type;
	file->file_name = ft_strdup(file_name);
	return (file);
}

t_file	*last_file(t_file *file)
{
	while (file && file->next)
		file = file->next;
	return (file);
}

void	append_file(t_file **file, t_file *n)
{
	if (!*file)
		*file = n;
	else
		last_file(*file)->next = n;
}

void	destroy_file(t_file *file)
{
	t_file	*tmp;

	while (file)
	{
		tmp = file;
		file = file->next;
		free(tmp->path_name);
		free(tmp->file_name);
		free(tmp);
	}
}

void	print_file(t_file *file)
{
	while (file)
	{
		if (file->type == DIRECTORY)
			printf("@");
		else
			printf(" ");
		printf("%s\n", file->path_name);
		file = file->next;
	}
}
