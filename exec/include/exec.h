/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:59:52 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/23 08:59:57 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>
# include "parser.h"
# include "s_data.h"
# include "builtins.h"

void	free_str_array(char **str);
int		count_lst_items(t_list *lst);
char	**lst_2_str(t_list *lst);
void	print_str_array(char **str);
int		is_a_directory(char *pathname);

int		set_input_stream(t_stream *stream);
int		set_output_stream(t_stream *stream, t_data *data);

int		run_simple_cmd(t_command *cmd, t_data *data);
void	ft_exec(t_data *data);
int		cmd_executor(t_data *data);

void	child(t_command *cmd, t_data *data);
int		wait_command(t_data *data);
void	fork_cmd_chain(t_command *user_cmd, t_data *data);
int		ft_execvpe(char **str_cmd, char **env);
char	*find_cmd_path(char *name, char **env);
void	link_2_next(int next_cmd, int stream, int fds[2]);
void	run_command(t_command *cmd, t_data *data, int f);
void	reset_std_stream(t_shell *sh);
int		execute(t_command *usr_cmd, t_data *data);
void	launch_cmd(t_command *user_cmd, t_data *data);
void	close_all_pipe_except(t_command *cmd);
void	close_pipe_stream(t_command *cmd);
void	ft_execute(t_command *cmd, t_data *data);
int		set_io_stream(t_command *cmd);
int		get_here_doc(t_here_doc *hd, t_data *data);
void	handle_here_doc(char *lim, t_shell *sh, int out_fd, int f);
#endif
