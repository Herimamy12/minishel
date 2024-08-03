/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:42:42 by nirirako@         #+#    #+#             */
/*   Updated: 2024/07/30 08:42:51 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int ft_is_whitespace(char c)
{
	return (c == ' ' || (c > 7 && c < 14));
}

int	ft_is_token(char token)
{
	return (token == '<' || token == '>' || token == '$' || token == '|');
}

int find_next_word(char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_is_whitespace(str[i]))
		i++;
	return (i);
}

int ft_is_input_stream(t_token *token)
{
	return (token->type == here_doc || token->type == input);
}

int ft_is_output_stream(t_token *token)
{
	return (token->type == output || token->type == append);
}