/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:20:05 by nirirako@         #+#    #+#             */
/*   Updated: 2024/09/19 12:20:54 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_H
# define WILDCARD_H
# include "ft_readdir.h"
# include "s_file.h"

void	insert2leaf(t_file *f, t_file **leaf, char *wildcard);
void	find_match(char *dir, char **pattern, t_file **files, char *wildcard);
void	free_temp_array(char **tmp);
t_file	*wild_expand(char *wild);
#endif
