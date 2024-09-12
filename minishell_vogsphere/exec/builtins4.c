/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins4.c                                        :+:      :+:    :+:   */
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
		report_error("exit: ");
		report_error(str);
		report_error(" : numeric argument required\n");
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

static int	handle_exit_next(t_data *data, int *exit_code)
{
	char	*str;

	str = (char *)data->cmd->args->next->content;
	if (is_not_digit (str))
		*exit_code = 2;
	else
	{
		if (data->cmd->args->next->next)
		{
			report_error(" too many arguments\n");
			data->sh->exit_code = EXIT_FAILURE;
			return (0);
		}
		*exit_code = get_exit_codes (str);
	}
	return (1);
}

void	handle_exit(t_data *data)
{
	int		exit_code;

	printf("Bye\n");
	exit_code = 0;
	if (data->cmd->args->next)
	{
		if (!handle_exit_next (data, &exit_code))
			return ;
	}
	else
	{
		exit_code = data->sh->exit_code;
		if (g_sigint_count)
			exit_code = 130;
	}
	destroy_data(data);
	rl_clear_history ();
	exit(exit_code);
}
