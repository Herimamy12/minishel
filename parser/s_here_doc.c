/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_here_doc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:19:08 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/27 08:59:17 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_here_doc.h"
#include "utility.h"

t_here_doc	*new_here_doc(char *lim)
{
	t_here_doc	*hd;

	hd = (t_here_doc *)malloc(sizeof(t_here_doc));
	if (!hd)
	{
		report_error("Malloc error in t_here_doc\n");
		return (NULL);
	}
	hd->lim = ft_strdup(lim);
	hd->pipe = new_pipe();
	return (hd);
}

void	destroy_here_doc(t_here_doc *hd)
{
	destroy_pipe(hd->pipe);
	free(hd->lim);
	free(hd);
}

void	print_here_doc(t_here_doc *hd)
{
	printf("[HERE_DOC : %s]\n", hd->lim);
}
