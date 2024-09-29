/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:32:05 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 13:32:07 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_HANDLER_H
# define SIG_HANDLER_H
# define DEFAULT -2
# define IGNORE  -3
# define HANDLER -4
# define HERE_DOC -5
# include <signal.h>
# include <stdio.h>
# include "libft.h"

extern sig_atomic_t	g_sigint_count;
void	sig_handler(int signum);
void	set_signal(int signum, int handler);
#endif
