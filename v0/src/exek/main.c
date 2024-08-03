/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:46:23 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/01 09:46:25 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exek.h"

int main(int c, char **v, char **env)
{
	char	*s_cmd = "ls > tmp | < Makefile cat -e";
	t_shell	*sh;
	t_data	*data;

	(void)c;
	(void)v;
	sh = new_shell(env);
	data = new_data (parse_command(s_cmd, sh), sh);
	if (data)
	{
		ft_exec(data);
		destroy_data(data);
	}
	return (0);
}
