/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:31:19 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 13:31:24 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "lexing.h"
# include "s_command.h"
# include "utility.h"
# include "sig_handler.h"
# include <readline/readline.h>
# include <readline/history.h>

t_token		*token_parser(char *cmd, t_shell *sh, int *exit_code);
t_token		*prompt_user(t_shell *sh);
t_command	*parse_command(t_token *token);
#endif
