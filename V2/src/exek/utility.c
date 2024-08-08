/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:46:50 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/01 09:47:14 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exek.h"

int	count_lst_items(t_list *lst)
{
	int	items;

	items = 0;
	while (lst)
	{
		lst = lst->next;
		items++;
	}
	return (items);
}

char	**lst_2_str(t_list *lst)
{
	int	items;
	char	**str;
	int	i;

	items = count_lst_items(lst);
	str = (char **)malloc((items + 1) * sizeof(char *));
	if (!str)
	{
		printf("Malloc error\n");
		return (NULL);
	}
	i = 0;
	while (lst)
	{
		str[i] = ft_strdup((char *)lst->content);
		i++;
		lst = lst->next;
	}
	str[i] = NULL;
	return (str);
}

void	print_str_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s ", str[i]);
		i++;
	}
	printf("\n");
}