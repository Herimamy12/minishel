/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:28:48 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/18 12:48:17 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"
#include "sig_handler.h"

void	report_error(char *error_msg)
{
	ft_putstr_fd(error_msg, 2);
}

char	*print_token_type(enum e_token type)
{
	if (type == pipes)
		return ("PIPES");
	else if (type == input)
		return ("INPUT");
	else if (type == here_doc)
		return ("HERE_DOC");
	else if (type == output)
		return ("OUTPUT");
	else if (type == append)
		return ("APPEND");
	else if (type == dollar)
		return ("DOLLAR");
	else if (type == space)
		return ("SPACE");
	else if (type == quote)
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
	if (!str[i])
		i--;
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
