#include "lexing.h"
#include "parser.h"

int main(int c, char **v, char **env)
{
	if (!c || !v)
		return 1;
	t_shell	*sh = new_shell(env);
	t_token *token = prompt_user(sh);

	print_token(token);
	destroy_token(token);
	destroy_shell(sh);
	return (0);
}
