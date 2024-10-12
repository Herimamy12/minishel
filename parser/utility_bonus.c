/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:29:01 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/12 08:24:00 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

int	match(char *input, char *pattern)
{
	int	f;

	f = 0;
	while (*pattern == '*' && ++f)
		pattern++;
	while (f && *input && *input != *pattern)
		input++;
	if (*input != *pattern)
		return (0);
	while (*input && *pattern && *pattern != '*' && *input == *pattern)
	{
		pattern++;
		input++;
	}
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

void	ft_append_str(char **src, char *s)
{
	int		i;
	char	*cp;
	char	*ptr;

	i = ft_strlen(*src) + ft_strlen(s) + 1;
	cp = (char *)malloc(sizeof(char) * i);
	ptr = cp;
	if (!cp)
	{
		report_error("Malloc error in ft_append_str\n");
		return ;
	}
	cp += ft_strlcpy(cp, *src, ft_strlen(*src) + 1);
	cp += ft_strlcpy(cp, s, ft_strlen(s) + 1);
	if (*src)
		free(*src);
	*src = ptr;
}
