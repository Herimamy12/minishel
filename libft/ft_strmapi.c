/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:55:08 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 13:55:14 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		index;

	if (s == NULL)
		return (NULL);
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	index = 0;
	if (str == NULL)
		return (str);
	while (*s)
	{
		str[index] = (*f)(index, *s);
		s++;
		index++;
	}
	str[index] = '\0';
	return (str);
}
