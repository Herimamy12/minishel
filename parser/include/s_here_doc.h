/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_here_doc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:24:43 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/28 12:24:45 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_HERE_DOC_H
# define S_HERE_DOC_H
# include "s_pipe.h"

typedef struct s_here_doc
{
	char	*lim;
	t_pipe	*pipe;	
}	t_here_doc;
t_here_doc	*new_here_doc(char *lim);
void		destroy_here_doc(t_here_doc *hd);
void		print_here_doc(t_here_doc *hd);
#endif
