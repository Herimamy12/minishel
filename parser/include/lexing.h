/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:01:05 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/20 11:01:25 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXING_H
# define LEXING_H
# include "token.h"

int			is_stream(enum e_token type);
int			check_syntax(t_token *token);
int			expand_token(t_token *token, t_shell *sh);
void		trim_token_type(t_token **token, enum e_token type_ref);
void		unify_token(t_token *token);
t_token		*lexicalize(t_token *token, t_shell *sh);
#endif
