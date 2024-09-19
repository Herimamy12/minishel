/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:39:03 by nirirako@         #+#    #+#             */
/*   Updated: 2024/09/17 12:39:12 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"
#include "sig_handler.h"

char	*expand(char *words, t_shell *sh)
{
	char	*e_var;

	if (*words == '$')
		words++;
	if (*words == '?')
	{
		if (g_sigint_count)
		{
			g_sigint_count = 0;
			return (ft_strdup("130"));
		}
		return (ft_itoa(get_exit_code(sh)));
	}
	if (*words == '_' || ft_isalpha(*words))
		e_var = get_env_var_value(sh->env, words);
	else
		e_var = ft_strdup(words + 1);
	return (e_var);
}
