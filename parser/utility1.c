/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako < nirirako@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:28:53 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 14:02:50 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

int	ft_is_input_stream(t_token *token)
{
	return (token->type == here_doc || token->type == input);
}

int	ft_is_output_stream(t_token *token)
{
	return (token->type == output || token->type == append);
}

int	ft_is_whitespace(char c)
{
	return (c == ' ' || (c >= 7 && c <= 13));
}

int	ft_is_str_empty(char *str)
{
	while (*str)
	{
		if (!ft_is_whitespace(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_quote_empty(char *str)
{
	str++;
	if (*str == '"')
		return (1);
	return (0);
}
