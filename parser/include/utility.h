/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:33:26 by nirirako          #+#    #+#             */
/*   Updated: 2024/09/29 13:33:29 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include "libft.h"
# include "s_shell.h"
# include "token.h"

void	report_error(char *error_msg);
char	*print_token_type(enum e_token type);
int		ft_strcmp(char *s1, char *s2);
char	**split_str(char *str);
char	*expand(char *words, t_shell *sh);
int		ft_is_input_stream(t_token *token);
int		ft_is_output_stream(t_token *token);
int		ft_is_whitespace(char c);
int		ft_is_str_empty(char *str);
int		is_quote_empty(char *str);
int		match(char *input, char *pattern);
void	ft_append_str(char **src, char *s);
#endif
