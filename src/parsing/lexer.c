/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:41:22 by nirirako@         #+#    #+#             */
/*   Updated: 2024/07/30 08:41:32 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_token	*tokenize(char *str_cmd)
{
	t_token	*token;

	token = NULL;
	while (*str_cmd)
	{
		str_cmd += find_next_word(str_cmd);
		while (*str_cmd && !ft_is_whitespace(*str_cmd))
		{
			if (ft_is_token(*str_cmd))
				str_cmd += handle_token(str_cmd, &token);
			else if (*str_cmd == '\'')
				str_cmd += handle_simple_quote(str_cmd, &token);
			else if (*str_cmd == '"')
				str_cmd += handle_double_quote(str_cmd, &token);
			else
				str_cmd += handle_word(str_cmd, &token);
		}
	}
	return (token);
}

t_token	*expand_token(t_token *token, t_shell *sh)
{
	t_token	*new;
	char	*tmp;

	new = NULL;
	while (token)
	{
		if (token->type != dollar)
			insert_token(&new, new_token(token->type, ft_strdup((char *)token->value)));
		else
		{
			token = token->next;
			tmp = ft_get_env(sh, (char *)token->value);
			if (tmp)
				insert_token(&new, new_token(word, tmp));
		}
		token = token->next;
	}
	return (new);
}

void	populate_command(t_command **cmd, t_token *token)
{
	t_token	*old;
	t_command	*curr_cmd;

	curr_cmd = last_command(*cmd);
	while (token)
	{
		if (ft_is_input_stream(token) || ft_is_output_stream(token))
		{
			old = token;
			token = token->next;
			if (ft_is_input_stream(old))
				insert_input(curr_cmd, new_stream(old->type, token->value));
			else
				insert_output(curr_cmd, new_stream(old->type, token->value));
		}
		else if (token->type == pipes)
		{
			append_command(cmd, new_command());
			curr_cmd = last_command(*cmd);
		}
		else
			insert_args(curr_cmd, ft_lstnew(ft_strdup(token->value)));
		token = token->next;
	}
}

t_command	*parse_command(char *str_cmd, t_shell *sh)
{
	t_token	*old;
	t_token	*new;
	t_command	*cmd;

	old = tokenize(str_cmd);
	print_token(old);
	new = expand_token(old, sh);
	if (check_syntax(new))
	{
		cmd = new_command();
		populate_command(&cmd, new);
	}
	else
	{
		cmd = NULL;
		printf("Unrecognised expression...\n");
	}
	destroy_token_chain(&old);
	destroy_token_chain(&new);
	return (cmd);
}