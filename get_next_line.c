/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:17:55 by emlicame      #+#    #+#                 */
/*   Updated: 2022/01/28 19:53:26 by emlicame      ########   odam.nl         */
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
	ssize_t			res;
	char			buff_line[BUFFER_SIZE + 1];
	static t_line	seek_new_line;
	char			*build_line;
	int				x;

	buff_line[BUFFER_SIZE] = '\0';
	seek_new_line.fd = fd;
	res = 1;
	x = 0;
	while (res)
	{
		res = read(fd, buff_line, BUFFER_SIZE);
		if (!res)
			break ;
		if (!build_line)
			build_line = ft_strdup(buff_line);
		else
		{
			x = check_where_newline(buff_line, '\n');
			printf ("%d", x++);
			build_line = ft_make_line(build_line, buff_line);
		}
	}
	write(1, build_line, ft_strlen(build_line));
	return (build_line);
}

char	*ft_make_line(char *build, char const *buff)
{
	char	*temp_line;

	temp_line = ft_strjoin(build, buff);
	build = ft_strdup(temp_line);
	return (build);
}

int	check_where_newline(char const *buff, int c)
{
	int	i;

	i = 0;
	while (buff[i] != c)
	{
		if (i == '\0')
			return (0);
		i++;
	}
	return (i);
}
