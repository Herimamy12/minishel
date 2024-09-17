/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:51:33 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/25 15:51:41 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	handle_unset(t_shell *sh, char **tmp)
{
	int	i;

	i = 1;
	while (tmp[i])
	{
		remove_from_env_lst(tmp[i], &sh->env);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	handle_pwd(void)
{
	char	buff[1000];

	getcwd(buff, 1000);
	printf("%s\n", buff);
	return (EXIT_SUCCESS);
}

static void	ft_echo(char **av, int f)
{
	int	i;

	i = 0;
	while (av[i])
	{
		printf("%s", av[i]);
		if (av[i + 1])
			printf(" ");
		i++;
	}
	if (f)
		printf("\n");
}

static int	is_argument(char *av)
{
	if (*av++ != '-')
		return (0);
	if (!*av)
		return (0);
	while (*av)
	{
		if (*av != 'n')
			return (0);
		av++;
	}
	return (1);
}

int	handle_echo(char **av)
{
	int	f;
	int	i;

	f = 1;
	i = 1;
	while (av[i] && is_argument(av[i]))
	{
		f = 0;
		i++;
	}
	ft_echo(av + i, f);
	return (EXIT_SUCCESS);
}
