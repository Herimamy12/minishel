/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_file.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:31:49 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 13:31:53 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_FILE_H
# define S_FILE_H
# include <stdlib.h>
# include "libft.h"
# define FILES -3
# define DIRECTORY -4

typedef struct s_file
{
	char			*path_name;
	char			*file_name;
	int				type;
	struct s_file	*next;
}	t_file;

t_file	*new_file(char *path_name, int type, char *file_name);
t_file	*last_file(t_file *file);
void	append_file(t_file **file, t_file *n);
void	destroy_file(t_file *file);
void	print_file(t_file *file);
#endif
