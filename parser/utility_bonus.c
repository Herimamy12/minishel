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

int	match(char *input, char *pattern)
{
	int	f;

	f = 0;
	while (*pattern == '*' && ++f)
		pattern++;
	if (!*pattern)
		return (1);
	while (f && *input && *input != *pattern)
		input++;
	while (*input && *pattern && *pattern != '*' && *input == *pattern)
	{
		pattern++;
		input++;
	}
	if (!*pattern)
		return (1);
	else if (!*input || *pattern != '*')
		return (0);
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
