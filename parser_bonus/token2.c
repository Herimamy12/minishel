/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:28:26 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/14 10:34:13 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "utility.h"

int	handle_1_quote(char *words, t_token **token)
{
	int		i;
	char	*str;

	i = 0;
	words++;
	if (!ft_strchr(words, '\''))
	{
		append_token(token, new_token(word, ft_strdup("'")));
		return (1);
	}
	while (words[i] && words[i] != '\'')
		i++;
	str = ft_substr(words, 0, i);
	escape_char(str, '*');
	append_token(token, new_token(quote, str));
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
