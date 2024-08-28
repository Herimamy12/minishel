/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:35:31 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/27 13:35:34 by nirirako@        ###   ########.fr       */
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

t_token		*token_parser(char *cmd, t_shell *sh);
t_token		*prompt_user(t_shell *sh);
t_command	*parse_command(t_token *token);
#endif
