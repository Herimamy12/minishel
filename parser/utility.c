/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:08:06 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/19 09:08:32 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"
#include "sig_handler.h"

void	report_error(char *error_msg)
{
	ft_putstr_fd(error_msg, 2);
}

char	*print_token_type(t_token *token)
{
	if (token->type == pipes)
		return ("PIPES");
	else if (token->type == input)
		return ("INPUT");
	else if (token->type == here_doc)
		return ("HERE_DOC");
	else if (token->type == output)
		return ("OUTPUT");
	else if (token->type == append)
		return ("APPEND");
	else if (token->type == dollar)
		return ("DOLLAR");
	else if (token->type == space)
		return ("SPACE");
	else if (token->type == quote)
		return ("QUOTE");
	return ("WORD");
}

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (-1);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	**split_str(char *str)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr = (char **)malloc(2 * sizeof(char *));
	if (!arr)
	{
		report_error("Malloc error in split_str\n");
		return (NULL);
	}
	while (str[i] && str[i] != '=')
		i++;
	arr[j++] = ft_substr(str, 0, i);
	str += (i + 1);
	i = 0;
	while (str[i])
		i++;
	arr[j] = ft_substr(str, 0, i);
	return (arr);
}

char	*expand(char *words, t_shell *sh)
{
	char	*e_var;

	if (*words == '?')
	{
		if (g_sigint_count)
		{
			g_sigint_count = 0;
			return (ft_strdup("130"));
		}
		return (ft_itoa(get_exit_code(sh)));
	}
	if (*words == '$')
		words++;
	e_var = get_env_var_value(sh->env, words);
	return (e_var);
}
