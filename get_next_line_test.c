/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_test.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:17:55 by emlicame      #+#    #+#                 */
/*   Updated: 2022/01/26 19:53:39 by emlicame      ########   odam.nl         */
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
	static t_line	*seek_new_line;

	if (fd == 0)
	{
		write (1, "File Error\n", 11);
		return (0);
	}
	seek_new_line = (t_line *)malloc(sizeof(t_line));
	if (!seek_new_line)
		return (NULL);
	seek_new_line->fd = fd;//seek_new_line->offset = res;
	building_line(fd);
	return ("char *");
}
//printf("%s\n", test_line);

char	*building_line(int fd)
{
	ssize_t			res;
	char			*buff_line;
	char			*test_line;

	buff_line = malloc(BUFFER_SIZE + 1);
	buff_line[BUFFER_SIZE] = '\0';
	test_line = malloc(BUFFER_SIZE + 1);
	test_line[BUFFER_SIZE] = '\0';
	res = 1;
	while (buff_line)
	{
		res = read(fd, buff_line, BUFFER_SIZE);
		if (!res)
			break ;
		ft_strlcat(test_line, buff_line, sizeof(test_line));
	}
	write(1, test_line, ft_strlen(test_line));
}
