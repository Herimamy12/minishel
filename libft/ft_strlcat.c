/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:54:37 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 13:54:38 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	is;
	int	id;
	int	room;

	id = ft_strlen(dst);
	is = ft_strlen(src);
	room = size - id - 1;
	if (room < 0)
		return (is + size);
	dst = dst + id;
	while (room > 0 && *src)
	{
		*dst = *src;
		src++;
		dst++;
		room--;
	}
	*dst = '\0';
	return (id + is);
}
