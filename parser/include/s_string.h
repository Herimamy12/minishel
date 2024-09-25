/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:01:31 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/19 09:01:51 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STRING_H
# define S_STRING_H
# include <stdlib.h>
# include <stdio.h>
# include "s_file.h"
# include "libft.h"

typedef struct s_string
{
	char			*words;
	struct s_string	*next;
	struct s_string	*prev;
}	t_string;

t_string	*new_string(char *words);
void		append_string(t_string **src, char *words);
void		destroy_string(t_string *words);
void		print_string(t_string *words);
t_string	*last_string(t_string *words);
char		*assemble(t_string *words);
int			string_length(t_string *words);
int			is_str_empty(t_string *string);
int			is_str_whitespace(t_string *string);
t_string	*file2str(t_file *file);
void		insert_string(t_string **string, t_string *n);
#endif
