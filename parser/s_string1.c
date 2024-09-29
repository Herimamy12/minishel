/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako < nirirako@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:27:52 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 14:02:11 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_string.h"
#include "utility.h"

int	string_length(t_string *words)
{
	int	i;

	i = 0;
	while (words)
	{
		i += ft_strlen(words->words);
		words = words->next;
	}
	return (i);
}

char	*assemble(t_string *words)
{
	char	*str;
	int		i;
	char	*ptr;

	i = string_length(words);
	if (i == 0)
		return (ft_strdup(""));
	str = (char *)malloc((i + 1) * sizeof(char));
	ptr = str;
	if (!str)
	{
		report_error("Malloc error in assemble\n");
		return (NULL);
	}
	while (words)
	{
		str += ft_strlcpy(str, words->words, ft_strlen(words->words) + 1);
		words = words->next;
	}
	return (ptr);
}

int	is_str_empty(t_string *string)
{
	char	*words;

	words = string->words;
	return (words[0] == 0);
}

int	is_str_whitespace(t_string *string)
{
	char	*words;

	words = string->words;
	return (ft_is_whitespace(words[0]));
}
