/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:27:57 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/12 08:23:44 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_string.h"

void	insert_string(t_string **string, t_string *n)
{
	t_string	*last;

	if (!*string)
	{
		*string = n;
		return ;
	}
	last = last_string(*string);
	last->next = n;
	n->prev = last;
}

t_string	*file2str(t_file *file)
{
	t_string	*str;

	str = NULL;
	while (file)
	{
		append_string(&str, ft_strtrim(file->path_name, "./"));
		if (file->next)
			append_string(&str, ft_strdup(" "));
		file = file->next;
	}
	return (str);
}
