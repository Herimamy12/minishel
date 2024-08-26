/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:18:39 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/23 08:18:41 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOC_H
# define HERE_DOC_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "s_string.h"
# include "s_pipe.h"
# include "s_shell.h"

typedef struct s_here_doc
{
	t_string	*value;
	t_pipe		*hd_pipe;
}	t_here_doc;

t_here_doc	*new_here_doc(char *lim, t_shell *sh);
void		destroy_here_doc(t_here_doc *hd);
t_string	*handle_here_doc(char *lim, t_shell *sh);
void		print_here_doc(t_here_doc *hd, int out_fd);
void	here_doc_handler(int signum);
#endif
