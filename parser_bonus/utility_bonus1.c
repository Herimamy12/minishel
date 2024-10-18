/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_bonus1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:36:15 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/18 09:37:10 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

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
