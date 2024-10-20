/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:55:33 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 13:56:30 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	comparer(const char *big, const char *little, size_t len)
{
	while (*big && *little && len-- > 0)
	{
		if (*big != *little)
			return (0);
		big++;
		little++;
	}
	if (!*big && *little)
		return (0);
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	ls;

	index = 0;
	ls = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	if (len == 0 || !big || len < ls)
		return (NULL);
	while (index++ <= len - ls && *big)
	{
		if (comparer(big, little, len))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
