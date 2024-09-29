/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:53:53 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 13:53:54 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	word_count(char const *s, char c)
{
	int	wc;

	wc = 0;
	if (*s == '\0')
		return (wc);
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
		s++;
	if (*(s - 1) != c)
		wc++;
	return (wc + word_count(s, c));
}

static int	word_length(char const *s, char c)
{
	int	l;

	l = 0;
	while (*s != c && *s)
	{
		s++;
		l++;
	}
	return (l);
}

static void	ft_free(char **str, int k)
{
	while (k-- > 0)
		free(str[k]);
	free(str);
}

static char	**iter_split(char const *s, char **str, int wc, char c)
{
	int		k;
	int		j;

	j = 0;
	while (wc > 0)
	{
		while (*s && *s == c)
			s++;
		k = word_length(s, c);
		if (k == 0)
			break ;
		str[j] = ft_substr(s, 0, k);
		if (!*str)
		{
			ft_free(str, j);
			return (NULL);
		}
		j++;
		s = s + k;
		wc--;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		wc;

	if (!s)
		return (NULL);
	wc = word_count(s, c);
	str = (char **)malloc((wc + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	return (iter_split(s, str, wc, c));
}
