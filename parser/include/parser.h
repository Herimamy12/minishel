/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:47:57 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/20 12:48:25 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "lexing.h"
# include "s_command.h"
# include "utility.h"
# include "sig_handler.h"

t_token		*cmd_parser(char *str_cmd, t_shell *sh);
t_token		*prompt_user(t_shell *sh);
t_command	*cmd_builder(t_token *token, t_shell *sh);
t_command	*build_cmd(char *str_cmd, t_shell *sh);
#endif
