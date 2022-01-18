/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:36:09 by emlicame      #+#    #+#                 */
/*   Updated: 2022/01/18 17:59:28 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

typedef struct s_line
{
	int		fd;
	char	build_line[BUFFER_SIZE];
	size_t	offset;
}t_line;

char	*get_next_line(int fd);