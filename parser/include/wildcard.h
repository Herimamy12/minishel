/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:33:33 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 13:33:38 by nirirako         ###   ########.fr       */
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
