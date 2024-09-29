/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako < nirirako@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:27:05 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 14:02:19 by nirirako         ###   ########.fr       */
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
	else
		sa.sa_handler = &sig_handler;
	sigaction(signum, &sa, NULL);
}
