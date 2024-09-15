/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:51:04 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/23 08:51:05 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sig_handler.h"
#include <readline/readline.h>
#include <readline/history.h>

sig_atomic_t	g_sigint_count = 0;

void	sig_handler(int signum)
{
	if (signum != SIGINT)
		return ;
	g_sigint_count = 1;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	set_signal(int signum, int handler)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	if (handler == IGNORE)
		sa.sa_handler = SIG_IGN;
	else if (handler == DEFAULT)
		sa.sa_handler = SIG_DFL;
	else if (handler == WAIT)
		sa.sa_handler = &sig_handler_wait;
	else
		sa.sa_handler = &sig_handler;
	sigaction(signum, &sa, NULL);
}
