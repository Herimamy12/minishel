/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:36:09 by nirirako@         #+#    #+#             */
/*   Updated: 2024/09/19 12:36:16 by nirirako@        ###   ########.fr       */
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
