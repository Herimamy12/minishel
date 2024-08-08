#ifndef EXEC_H
# define EXEC_H
# include "exek.h"
# include "builtins.h"
# define DEFAULT -2
# define IGNORE  -3

void	link_2_next(int next_cmd, int stream, int fds[2]);
void	run_command(t_command *cmd, t_data *data, int f);
void reset_std_stream(t_shell *sh);
void sig_handler(int signum);
int	execute(t_command *usr_cmd, t_data *data);
#endif