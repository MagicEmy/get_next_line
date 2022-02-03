/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 16:12:06 by emlicame      #+#    #+#                 */
/*   Updated: 2022/02/03 17:40:53 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <unistd.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int		check_where_newline(char *buff, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_is_new_line(char *static_buff);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*read_the_buffer(int fd);
#endif