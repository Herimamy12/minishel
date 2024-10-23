/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:31:19 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/14 14:56:18 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "lexing.h"
# include "s_command.h"
# include "utility.h"
# include "ft_readdir.h"
# include "sig_handler.h"
# include "wildcard.h"
# include <readline/readline.h>
# include <readline/history.h>

t_token		*token_parser(char *cmd, t_shell *sh, int *exit_code);
t_token		*prompt_user(t_shell *sh);
t_command	*parse_command(t_token *token);
t_command	*command_parser(char *str_cmd, t_shell *sh);
t_string	*slice_1(char *cmd);
#endif
