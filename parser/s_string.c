/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:02:28 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/19 09:02:38 by nirirako@        ###   ########.fr       */
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
	return (string);
}

void	append_string(t_string **src, char *words)
{
	if (!*src)
		*src = new_string(words);
	else
		last_string(*src)->next = new_string(words);
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
