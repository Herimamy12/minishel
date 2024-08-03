#include "core.h"

sig_atomic_t	sigint_count = 0;

void	handler(int signum)
{
	(void)signum;

	sigint_count = 1;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void handle_user_cmd(char *str_cmd, t_shell *sh)
{
	t_data	*data;

	data = new_data(parse_command(str_cmd, sh), sh);
	if (!data)
		return ;
	ft_exec(data);
	destroy_command(data->cmd);
	free(data);
	dup2(sh->stdin, 0);
	dup2(sh->stdout, 1);
}

void	handle_main_loop(t_shell *sh)
{
	char	*str_cmd;

	while (1)
	{
		if (!sigint_count)
			str_cmd = readline("%% ");
		else
			sigint_count = 0;
		if (str_cmd)
		{
			handle_user_cmd(str_cmd, sh);
			free(str_cmd);
		}
		else
		{
			printf("Bye\n");
			break ;
		}
	}
}

int main(int c, char **v, char **env)
{
	t_shell	*sh;
	struct sigaction	sa;

	if (c < 0 || !v)
		return (1);
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &handler;
	sigaction(SIGINT, &sa, NULL);
	sh = new_shell(env);
	if (sh)
	{
		handle_main_loop(sh);
		destroy_shell(sh);
	}
	return (0);
}
