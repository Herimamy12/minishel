/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_pipe.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:32:11 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 13:32:14 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PIPE_H
# define S_PIPE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_pipe
{
	int	fds[2];
}	t_pipe;

t_pipe	*new_pipe(void);
void	destroy_pipe(t_pipe *pipes);
void	set_pipe_2_input(t_pipe *pipes);
void	set_pipe_2_output(t_pipe *pipes);
void	close_pipe(t_pipe *pipes);
#endif
