/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:45:29 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/19 09:45:48 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "token.h"
#include "libft.h"
#include "utility.h"

static int	handle_tokens(char *cmd, t_string **string)
{
	if (is_token(cmd[1]) && cmd[1] == cmd[0])
	{
		append_string(string, ft_substr(cmd, 0, 2));
		return (2);
	}
	append_string(string, ft_substr(cmd, 0, 1));
	return (1);
}

static int	handle_quote(char *cmd, t_string **string)
{
	char	quote;
	int		i;

	i = 0;
	quote = cmd[i++];
	if (cmd[i] == quote)
	{
		append_string(string, ft_strdup("''"));
		return (i + 1);
	}
	while (cmd[i] && cmd[i] != quote)
		i++;
	append_string(string, ft_substr(cmd, 0, i + 1));
	if (cmd[i] == quote)
		i++;
	return (i);
}

static int	handle_word(char *cmd, t_string **string)
{
	int	i;

	i = 0;
	while (cmd[i] && cmd[i] != '\'' && cmd[i] != '"'
		&& !ft_is_whitespace(cmd[i]))
	{
		if (cmd[i] != '$' && is_token(cmd[i]))
			break ;
		i++;
	}
	append_string(string, ft_substr(cmd, 0, i));
	return (i);
}

int	is_token(char c)
{
	return (c == '<' || c == '>' || c == '|' || c == '$');
}

t_string	*slice(char *cmd)
{
	t_string	*string;
	int			f;

	string = NULL;
	while (*cmd)
	{
		f = 0;
		while (*cmd && (*cmd == 32 || (*cmd > 8 && *cmd < 14)))
		{
			cmd++;
			f = 1;
		}
		if (f)
			append_string(&string, ft_strdup(" "));
		if (!*cmd)
			break ;
		if (*cmd != '$' && is_token(*cmd))
			cmd += handle_tokens(cmd, &string);
		else if (*cmd == '\'' || *cmd == '"')
			cmd += handle_quote(cmd, &string);
		else
			cmd += handle_word(cmd, &string);
	}
	return (string);
}
