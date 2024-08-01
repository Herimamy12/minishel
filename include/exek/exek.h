/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exek.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:44:04 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/01 09:44:33 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEK_H
# define EXEK_H
# include "parsing.h"
# include <sys/types.h>
# include <sys/wait.h>

int	count_lst_items(t_list *lst);
char	**lst_2_str(t_list *lst);
void	print_str_array(char **str);
#endif
