/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:31:04 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 13:31:14 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXING_H
# define LEXING_H
# include "token.h"

int			is_stream(enum e_token type);
t_token *expand_wildcard(char *pattern);
void	link_token(t_token *token);
int			check_syntax(t_token *token);
int			expand_token(t_token *token, t_shell *sh);
void		trim_token_type(t_token **token, enum e_token type_ref);
void		unify_token(t_token *token);
t_token		*lexicalize(t_token *token, t_shell *sh);
#endif
