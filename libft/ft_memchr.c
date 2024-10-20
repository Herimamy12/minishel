/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:52:01 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 13:52:02 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*ptr;

	index = 0;
	ptr = (unsigned char *)s;
	while (index < n)
	{
		if (*(ptr + index) == (unsigned char )c)
			return ((void *)(s + index));
		index++;
	}
	return (NULL);
}
