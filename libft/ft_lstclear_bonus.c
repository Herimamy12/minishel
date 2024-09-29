/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:50:57 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 13:50:58 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next;

	temp = *lst;
	next = temp -> next;
	if (!*lst)
		return ;
	while (next != NULL)
	{
		ft_lstdelone(temp, del);
		temp = next;
		next = temp -> next;
	}
	ft_lstdelone(temp, del);
	*lst = NULL;
}
