/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:05:31 by nirirako@         #+#    #+#             */
/*   Updated: 2024/09/19 10:06:25 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READDIR_H
# define FT_READDIR_H
# include "s_file.h"
# include <dirent.h>
# include "utility.h"

t_file	*ft_readdir(char *dir);
t_file	*f_grep(char *path, char *pattern);
#endif
