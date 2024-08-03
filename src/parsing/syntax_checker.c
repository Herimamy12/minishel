/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:02:26 by nirirako@         #+#    #+#             */
/*   Updated: 2024/07/31 11:02:37 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_syntax(t_token *token)
{
	if (!token)
		return (1);
	while (token)
	{
		if (token->type != word)
		{
			if (!token->next)
				return (0);
			else if (token->type == pipes)
			{
				if (token->next->type != word && !ft_is_input_stream(token->next)
					&& !ft_is_input_stream(token->next))
					return (0);
			}
			else if (token->next->type != word)
				return (0);
		}
		token = token->next;
	}
	return (1);
}