/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 16:13:10 by emlicame      #+#    #+#                 */
/*   Updated: 2022/02/01 18:43:44 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t	res;
	char	*build_line;
	char	*part_line;
	char	buff_line[BUFFER_SIZE + 1];
	int		nl_index;

	nl_index = 0;
	res = 1;
	build_line = NULL;
	part_line = NULL;
	buff_line[BUFFER_SIZE] = '\0';
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (res)
	{
		res = read(fd, buff_line, BUFFER_SIZE);
		if (!res)
			break ;
		if (check_where_newline(buff_line, '\n') == -1)
		{
			if (!build_line)
				build_line = ft_strdup(buff_line);// move after \n check =substr
			build_line = ft_strjoin(build_line, buff_line);
		}
		else
		{
			part_line = ft_is_new_line(buff_line);
			if (!build_line)
				build_line = ft_strdup(part_line);
			build_line = ft_strjoin(build_line, part_line);
		}
	}
	write(1, build_line, ft_strlen(build_line));
	return (build_line);
}

int	check_where_newline(char const *buff, int c)
{
	int	i;

	i = 0;
	while (buff[i] != c)
	{
		if (buff[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

char	*ft_is_new_line(char const *buff)
{
	unsigned int	index;
	static char		*static_buff;
	char			*part;

	index = 0;
	static_buff = ft_strdup(buff);
	index = check_where_newline(static_buff, '\n');
	part = ft_substr(buff, index + 1, ft_strlen(static_buff) - index);
	return (part);
}
