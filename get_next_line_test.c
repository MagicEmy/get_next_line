/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_test.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:17:55 by emlicame      #+#    #+#                 */
/*   Updated: 2022/01/27 19:20:49 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*filename;

	i = 0;
	filename = "Text.txt";
	fd = open (filename, O_RDONLY);
	get_next_line(fd);
	close (fd);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_line	seek_new_line;
	ssize_t			res;
	char			buff_line[BUFFER_SIZE + 1];
	int				i;

	i = 0;
	buff_line[BUFFER_SIZE] = '\0';
	res = 1;
	while (res)
	{
		res = read(fd, buff_line, BUFFER_SIZE);
		if (!res)
			break ;
		if (!seek_new_line.build_line)
			seek_new_line.build_line = ft_strdup(buff_line);
		else
		{
			ft_strjoin(seek_new_line.build_line, buff_line);
			printf("%d\n", i++);
			printf("%s\n", buff_line);
		}
	}
	write(1, seek_new_line.build_line, ft_strlen(seek_new_line.build_line));
	return ("char");
}
