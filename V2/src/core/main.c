#include "core.h"

void	handler(int signum)
{
	(void)signum;

	sigint_count = 1;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int handle_user_cmd(char *str_cmd, t_shell *sh)
{
	t_data	*data;
	char	*first_cmd;
	int		r;

	data = new_data(parse_command(str_cmd, sh), sh);
	if (!data)
		return -1;
	first_cmd = (char *)data->cmd->args->content;
	if (ft_strlen(first_cmd) == 4 && !ft_strncmp(first_cmd, "exit", 4))
	{
		if (data->cmd->next == NULL)
			r = -1;
	}
	else
		r = execute(data->cmd, data);
	destroy_command(data->cmd);
	free(data);
	dup2(sh->stdin, 0);
	dup2(sh->stdout, 1);
	return (r);
}

void	handle_main_loop(t_shell *sh, struct sigaction *sa)
{
	char	*str_cmd;

	str_cmd = "";
	while (1)
	{
		sigaction(SIGINT, sa, NULL);
		if (!sigint_count)
			str_cmd = readline("$> ");
		else
			sigint_count = 0;
		if (!sigint_count)
		{
			if (str_cmd)
			{
				if (handle_user_cmd(str_cmd, sh) < 0)
				{
					free(str_cmd);
					break ;
				}
			}
			else
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
	sh = new_shell(env);
	handle_main_loop(sh, &sa);
	destroy_shell(sh);
	printf("Bye\n");
	return (0);
}
