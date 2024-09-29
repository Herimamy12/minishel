/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako < nirirako@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:28:26 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 14:03:33 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int	handle_1_quote(char *words, t_token **token)
{
	int	i;

	i = 0;
	words++;
	if (!ft_strchr(words, '\''))
	{
		append_token(token, new_token(word, ft_strdup("'")));
		return (1);
	}
	while (words[i] && words[i] != '\'')
		i++;
	append_token(token, new_token(quote, ft_substr(words, 0, i)));
	return (i + 2);
}

int	handle_words(char *words, t_token **token)
{
	int	i;

	i = 0;
	if (!ft_isalnum(words[i]) && words[i] != '_')
	{
		append_token(token, new_token(word, ft_substr(words, 0, 1)));
		return (1);
	}
	while (words[i] && !is_token(words[i]) && words[i] != '"')
	{
		if (!ft_isalnum(words[i]) && words[i] != '_')
			break ;
		i++;
	}
	append_token(token, new_token(word, ft_substr(words, 0, i)));
	return (i);
}
