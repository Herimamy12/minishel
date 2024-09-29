/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:30:19 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 13:30:21 by nirirako         ###   ########.fr       */
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
