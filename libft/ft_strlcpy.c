/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:54:44 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 13:54:45 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (dst == NULL || src == NULL)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while (index < size - 1 && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	while (src[index])
		index++;
	return (index);
}
