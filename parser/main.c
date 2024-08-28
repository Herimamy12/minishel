/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:02:06 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/19 09:02:22 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parser.h"

int	main(int argc, char **argv, char **env)
{
	t_shell	*sh;
	t_token	*token;

	if (!argc || !argv || !env)
		return (1);
	sh = new_shell(env);
	token = prompt_user(sh);
	print_token(token);
	destroy_token(token);
	destroy_shell(sh);
	rl_clear_history();
	return (0);
}
