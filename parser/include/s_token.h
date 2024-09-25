/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_token.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:24:50 by nirirako@         #+#    #+#             */
/*   Updated: 2024/08/23 08:24:54 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_TOKEN_H
# define S_TOKEN_H
# include "s_string.h"

enum e_token
{
	pipes,
	input,
	here_doc,
	output,
	append,
	dollar,
	word,
	space,
	quote
};

typedef struct s_token
{
	enum e_token	type;
	t_string		*value;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

t_token	*new_token(enum e_token type, char *value);
t_token	*last_token(t_token *token);
void	append_token(t_token **src, t_token *token);
void	destroy_token(t_token *token);
void	print_token(t_token *token);
#endif
