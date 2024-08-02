/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exek.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:44:04 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/01 09:44:33 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEK_H
# define EXEK_H
# include "parsing.h"
# include "s_data.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

int	count_lst_items(t_list *lst);
char	**lst_2_str(t_list *lst);
void	print_str_array(char **str);
// input & output stream
int	set_input_stream(t_stream *stream, t_data *data);
int	set_output_stream(t_stream *stream, t_data *data);
// exek
int	run_simple_cmd(t_command *cmd, t_data *data);
void	ft_exec(t_data *data);
#endif
