/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:29:01 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/18 09:37:01 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

void	escape_char(char *str, char car)
{
	while (str && *str)
	{
		if (*str == car)
			*str = 1;
		str++;
	}
}

void	unescape_char(char *str)
{
	while (str && *str)
	{
		if (*str == 1)
			*str = '*';
		str++;
	}
}

static int	core_match(char *input, char *pattern)
{
	int	i;

	i = 0;
	while (*input && *pattern && *pattern != '*')
	{
		if (*input == '*' && *pattern != 1)
			break ;
		if (*input != '*' && *input != *pattern)
			break ;
		pattern++;
		input++;
		i++;
	}
	return (i);
}

static int	ft_equal(char i, char p)
{
	if (p == 1 && i == '*')
		return (1);
	return (i == p);
}

int	match(char *input, char *pattern)
{
	int	f;
	int	i;

	f = 0;
	while (*pattern == '*' && ++f)
		pattern++;
	while (f && *input && !ft_equal(*input, *pattern))
		input++;
	if (!ft_equal(*input, *pattern))
		return (0);
	i = core_match(input, pattern);
	input += i;
	pattern += i;
	if (*pattern != '*')
	{
		if (!*pattern && !*input)
			return (1);
		if (!*input && !f)
			return (0);
	}
	while (f && *pattern != '*')
		pattern--;
	return (match(input, pattern));
}
