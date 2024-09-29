/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:57:00 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 13:57:01 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	l;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	l = ft_strlen(s + start);
	if (l > len)
		l = len;
	str = (char *)malloc((l + 1) * sizeof(char));
	if (!str)
		return (str);
	ft_strlcpy(str, s + start, l + 1);
	return (str);
}
