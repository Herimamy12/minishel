/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:16:08 by nirirako@         #+#    #+#             */
/*   Updated: 2024/03/06 10:16:10 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	my_strlen(char const *s);
size_t	my_strlcpy(char *dst, const char *src, size_t size);
char	*my_substr(char const *s, unsigned int start, size_t len);
char	*my_append(char *str, char const *s);
char	*my_substr(char const *s, unsigned int start, size_t len);
char	*my_left_string(char *str);
char	*my_extract(char *str, char c);
char	*my_strchr(const char *s, int c);
char	*my_read_line(int fd, int buf_size);
char	*get_next_line(int fd, char **ptr);

#endif
