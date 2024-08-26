/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:18:15 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/24 08:51:02 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	free_str_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

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
	int		items;
	char	**str;
	int		i;

	if (!lst)
		return (NULL);
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
		printf("%s [%d]", str[i], str[i][0]);
		i++;
	}
	printf("\n");
}
