/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:47:45 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/19 09:47:46 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include "s_token.h"
# include "libft.h"
# include "s_env.h"
# include "s_shell.h"

int			is_token(char c);
t_string	*slice(char *cmd);
int			handle_token(char *words, t_token **token, int f);
int			handle_1_quote(char *words, t_token **token);
int			handle_words(char *words, t_token **token);
int			handle_2_quote(char *words, t_token **token, t_shell *sh);
t_token		*tokenize_string(t_string *string, t_shell *sh, int f);
int			check_token_syntax(t_token *token);
t_token		*tokenify(t_string *string, t_shell *sh);
#endif
