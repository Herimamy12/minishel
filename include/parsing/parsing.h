/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:44:08 by nirirako@         #+#    #+#             */
/*   Updated: 2024/07/30 08:44:47 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "token.h"
# include "s_shell.h"
# include "s_stream.h"
# include "s_command.h"
# include <unistd.h>

// utility
int	ft_is_token(char token);
int find_next_word(char *str);
int ft_is_whitespace(char c);
void	free_str_array(char **str);
int ft_is_output_stream(t_token *token);
int ft_is_input_stream(t_token *token);
// handler
int handle_token(char *str_cmd, t_token **token);
int handle_word(char *str_cmd, t_token **token);
int handle_simple_quote(char *str_cmd, t_token **token);
int extract_word(char *str_cmd, t_token **token, int f);
int handle_double_quote(char *str_cmd, t_token **token);
// lexer
t_token	*tokenize(char *str_cmd);
t_token	*expand_token(t_token *token, t_shell *sh);
t_command	*parse_command(char *str_cmd, t_shell *sh);
void	populate_command(t_command **cmd, t_token *token);
int	check_syntax(t_token *token);
#endif
