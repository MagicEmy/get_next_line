/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:36:09 by emlicame      #+#    #+#                 */
/*   Updated: 2022/01/24 19:27:09 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_line
{
	int		fd;
	char	build_line[BUFFER_SIZE];
	ssize_t	offset;
}t_line;

char	*get_next_line(int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t dsize);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
#endif
