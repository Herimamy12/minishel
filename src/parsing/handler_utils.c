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
