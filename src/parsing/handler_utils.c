/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:16:48 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/01 09:16:59 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	handle_dollar(char *str_cmd, t_token **token)
{
	int	i;

	i = 1;
	insert_token(token, new_token(dollar, NULL));
	if (str_cmd[1] == '?')
	{
		insert_token(token, new_token(word, ft_strdup("?")));
		i = 2;
	}
	return (i);
}

int prepare_to_merge(t_token *token)
{
	int items;

	items = 0;
	token = token->next;
	while (token->type != merge)
	{
		items += ft_strlen((char *)token->value);
		token = token->next;
	}
	return (items + 1);
}

char	*merge_tokens(t_token *token)
{
	int items;
	char	*merged_value;
	char	*ptr;

	items = prepare_to_merge(token);
	merged_value = (char *)malloc(items * sizeof(char));
	ptr = merged_value;
	if (!merged_value)
	{
		printf("Malloc error\n");
		return (NULL);
	}
	token = token->next;
	while (token->type != merge)
	{
		merged_value += ft_strlcpy(merged_value, (char *)token->value, 1000);
		token = token->next;
	}
	return (ptr);
}

void	handle_merge(t_token *token)
{
	char	*merged_token;
	t_token	*head;
	t_token	*tmp;

	merged_token = merge_tokens(token);
	token->type = word;
	token->value = merged_token;
	head = token;
	token = token->next;
	while (token->type != merge)
	{
		tmp = token;
		token = token->next;
		destroy_token(tmp);
	}
	tmp = token;
	token = token->next;
	destroy_token(tmp);
	head->next = token;
}

void	refine_token(t_token *token)
{
	while (token)
	{
		if (token->type == merge)
			handle_merge(token);
		token = token->next;
	}
}
