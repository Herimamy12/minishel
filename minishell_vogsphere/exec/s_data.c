/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:14:12 by nherimam          #+#    #+#             */
/*   Updated: 2024/08/02 09:14:16 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_data.h"

t_data	*new_data(t_command *cmd, t_shell *sh)
{
	t_data	*data;

	if (!cmd && !sh)
		return (NULL);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		printf("%s\n", "new data error");
		return (NULL);
	}
	data->sh = sh;
	data->cmd = cmd;
	data->token = NULL;
	return (data);
}

void	destroy_data(t_data *data)
{
	if (data->cmd)
		destroy_command (data->cmd);
	if (data->sh)
		destroy_shell (data->sh);
	if (data->token)
		destroy_token(data->token);
	free (data);
}
