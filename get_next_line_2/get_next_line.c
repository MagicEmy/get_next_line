/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 16:13:10 by emlicame      #+#    #+#                 */
/*   Updated: 2022/02/03 18:42:44 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*build_line;
	static char	*buff_line;

	build_line = ft_strdup("");
	buff_line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff_line = read_the_buffer(fd);
	build_line = ft_strjoin(build_line, buff_line);
	free (buff_line);
	if (!build_line)
		return (NULL);
	return (build_line);
}

char	*read_the_buffer(int fd)
{
	ssize_t			res;
	char			*r_line;
	static char		static_buff[BUFFER_SIZE + 1];

	res = 1;
	r_line = ft_strdup("");
	if (!r_line)
		return (NULL);
	while (res)
	{
		res = read(fd, static_buff, BUFFER_SIZE);
		if (res == -1)
		{
			free(static_buff);
			return (NULL);
		}
		if (check_where_newline(static_buff, '\n') == -1)
			r_line = ft_strjoin(r_line, static_buff);
		else
			r_line = ft_is_new_line(static_buff);
	}
	return (r_line);
}

int	check_where_newline(char *buff, int c)
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

char	*ft_is_new_line(char *static_buff)
{
	unsigned int	index;
	char			*temp;
	char			*part;
	int				i;

	i = 0;
	index = 0;
	temp = ft_strdup(static_buff);
	index = check_where_newline(temp, '\n');
	part = ft_substr(temp, 0, ft_strlen(temp) - index);
	index++;
	while (temp[index] != '\0')
	{
		static_buff[i] = temp[index];
		index++;
		i++;
	}
	static_buff[i] = '\0';
	free (temp);
	return (part);
}
