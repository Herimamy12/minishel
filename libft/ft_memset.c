/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:52:46 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 13:52:47 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	index;

	if (s == NULL)
		return (s);
	index = 0;
	while (index < n)
	{
		*((char *) s + index) = (char) c;
		index++;
	}
	return ((void *) s);
}
