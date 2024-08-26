/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:55:28 by nherimam          #+#    #+#             */
/*   Updated: 2024/08/20 10:55:30 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	is_not_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i + 1] && ft_isdigit (str[i]))
		i++;
	if (!ft_isdigit (str[i]))
	{
		printf("minishell: exit: %s: numeric argument required\n", str);
		return (2);
	}
	return (0);
}

static int	get_exit_codes(char *str)
{
	unsigned int	value;

	value = (unsigned int) ft_atoi (str);
	value = value % 256;
	return (value);
}

void	handle_exit(t_data *data)
{
	char	*str;
	int		exit_code;

	if (data->cmd->args->next)
	{
		str = (char *)data->cmd->args->next->content;
		if (is_not_digit (str))
			exit_code = 2;
		else
			exit_code = get_exit_codes (str);
	}
	else
		exit_code = data->sh->exit_code;
	printf("exit\n");
	destroy_data(data);
	rl_clear_history ();
	exit(exit_code);
}
