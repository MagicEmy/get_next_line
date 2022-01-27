/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:17:55 by emlicame      #+#    #+#                 */
/*   Updated: 2022/01/27 17:29:23 by emlicame      ########   odam.nl         */
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
	char			*buff_line;
	char			test_line[10000];
	ssize_t			res;

	res = 1;
	buff_line = malloc(BUFFER_SIZE + 1);
	buff_line[BUFFER_SIZE] = '\0';
	//test_line = malloc(BUFFER_SIZE + 1);
	//test_line[BUFFER_SIZE] = '\0';
	if (fd == 0)
	{
		write (1, "File Error\n", 11);
		return (0);
	}
	seek_new_line = (t_line *)malloc(sizeof(t_line));
	if (!seek_new_line)
		return (NULL);
	seek_new_line->fd = fd;
	while (buff_line)
	{
		res = read(fd, buff_line, BUFFER_SIZE);
		ft_strlcat(test_line, buff_line, sizeof(test_line));
		seek_new_line->offset = res;
		if (!res)
			break ;
	}
	write(1, test_line, ft_strlen(test_line));
	return ("char");
}
//printf("%s\n", test_line);