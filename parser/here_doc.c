/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:30:21 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/21 07:30:30 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "here_doc.h"
#include "utility.h"
#include "libft.h"

t_here_doc	*new_here_doc(char *lim, t_shell *sh)
{
	t_here_doc	*hd;

	hd = (t_here_doc *)malloc(sizeof(t_here_doc));
	if (!hd)
	{
		report_error("Malloc error in t_here_doc\n");
		return (NULL);
	}
	hd->hd_pipe = NULL;
	hd->value = handle_here_doc(lim, sh);
	return (hd);
}

void	destroy_here_doc(t_here_doc *hd)
{
	if (hd->hd_pipe)
		destroy_pipe(hd->hd_pipe);
	destroy_string(hd->value);
	free(hd);
}

void	print_here_doc(t_here_doc *hd, int out_fd)
{
	t_string	*string;

	string = (t_string *)hd->value;
	while (string)
	{
		ft_putstr_fd(string->words, out_fd);
		ft_putstr_fd("\n", out_fd);
		string = string->next;
	}
}
