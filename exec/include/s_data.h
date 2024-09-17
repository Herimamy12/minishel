/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:09:02 by nherimam          #+#    #+#             */
/*   Updated: 2024/08/02 09:09:05 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_DATA_H
# define S_DATA_H
# include "s_command.h"

typedef struct s_data
{
	t_command	*cmd;
	t_shell		*sh;
	t_token		*token;
}				t_data;

t_data	*new_data(t_command *cmd, t_shell *sh);
void	destroy_data(t_data *data);

#endif
