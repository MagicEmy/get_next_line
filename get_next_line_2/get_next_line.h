/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 16:12:06 by emlicame      #+#    #+#                 */
/*   Updated: 2022/02/05 19:38:45 by emlicame      ########   odam.nl         */
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
char	*read_the_buffer(int fd, char *buff_line);
char	*ft_update_buffer(char *buff_line);
char	*ft_substr(char const *s, size_t start, size_t len);
#endif