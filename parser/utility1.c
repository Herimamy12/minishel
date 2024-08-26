/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:07:25 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/20 14:07:33 by nirirako@        ###   ########.fr       */
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
