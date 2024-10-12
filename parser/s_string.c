/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:27:47 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/12 08:23:39 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_string.h"
#include "utility.h"

t_string	*new_string(char *words)
{
	t_string	*string;

	string = (t_string *)malloc(sizeof(t_string));
	if (!string)
	{
		report_error("Malloc error new_string()\n");
		return (NULL);
	}
	string->words = words;
	string->next = NULL;
	string->prev = NULL;
	return (string);
}

void	append_string(t_string **src, char *words)
{
	t_string	*last;
	t_string	*new;

	if (!*src)
		*src = new_string(words);
	else
	{
		last = last_string(*src);
		new = new_string(words);
		last->next = new;
		new->prev = last;
	}
}

void	destroy_string(t_string *words)
{
	t_string	*tmp;

	while (words)
	{
		tmp = words;
		words = words->next;
		free(tmp->words);
		free(tmp);
	}
}

void	print_string(t_string *words)
{
	while (words)
	{
		printf("%s -> ", words->words);
		words = words->next;
	}
	printf("EOS");
}

t_string	*last_string(t_string *words)
{
	while (words->next)
		words = words->next;
	return (words);
}
