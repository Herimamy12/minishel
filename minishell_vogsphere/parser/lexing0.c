/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:29:43 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/23 08:29:45 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexing.h"
#include "utility.h"

static int	check_pipe(t_token *token)
{
	if (!token->prev)
		return (0);
	if (token->next)
	{
		token = token->next;
		if (token->type == space)
		{
			if (token->next)
			{
				token = token->next;
				if (token->type == pipes)
					return (0);
				else
					return (1);
			}
			return (1);
		}
		else if (token->type == pipes)
			return (0);
	}
	return (1);
}

static int	check_stream(t_token *token)
{
	if (token->next)
	{
		if (token->next->type == space)
		{
			token = token->next;
			if (token->next)
			{
				if (is_stream(token->next->type) || token->next->type == pipes)
					return (0);
				return (1);
			}
			return (0);
		}
		else
		{
			if (is_stream(token->next->type) || token->next->type == pipes)
				return (0);
			return (1);
		}
	}
	return (0);
}

int	is_stream(enum e_token type)
{
	if (type == here_doc || type == input || type == output || type == append)
		return (1);
	return (0);
}

int	check_syntax(t_token *token)
{
	while (token)
	{
		if (is_stream(token->type) && !check_stream(token))
		{
			report_error("Syntax error near token ");
			report_error(print_token_type(token->type));
			report_error("\n");
			return (0);
		}
		if (token->type == pipes && !check_pipe(token))
		{
			report_error("Syntax error near token PIPE\n");
			return (0);
		}
		token = token->next;
	}
	return (1);
}
