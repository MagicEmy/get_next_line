/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_test.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:17:55 by emlicame      #+#    #+#                 */
/*   Updated: 2022/01/24 19:29:33 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*filename;

	filename = "Text.txt";
	fd = open (filename, O_RDONLY);
	get_next_line(fd);
	close (fd);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_line	*seek_new_line;
	char			*buff_line;
	ssize_t			res;

	res = 0;
	buff_line = "start";
	if (fd == 0)
	{
		write (1, "File Error\n", 11);
		return (0);
	}
	printf("step 1\n");
	seek_new_line = (t_line *)malloc(sizeof(t_line));
	if (!seek_new_line)
		return (NULL);
	seek_new_line->fd = fd;
	printf("step 2\n");
	while (buff_line)
	{
		res = read (fd, &buff_line, BUFFER_SIZE);
		if (!res)
			exit(0);
		seek_new_line->offset = res;
		seek_new_line->build_line = ft_strlcat(build_line, buff_line, \
		ft_strlen(build_line));
		write (1, &build_line, ft_strlen(build_line));
	}
	printf("step 3\n");
	buff_line [res] = '\0';
	return (buff_line);
}
