/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 17:58:35 by emlicame      #+#    #+#                 */
/*   Updated: 2022/02/16 20:10:42 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buff_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!buff_line)
	{
		buff_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		buff_line[0] = '\0';
	}
	if (!buff_line)
		return (NULL);
	line = read_bytes(fd, buff_line);
	if (!line)
		return (NULL);
	line = check_data_in_buffer(line, buff_line);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_bytes(int fd, char *buff_line)
{
	int			x;
	ssize_t		res;
	char		*r_line;

	res = 1;
	r_line = (char *)malloc(1 * sizeof(char));
	if (!r_line)
		return (NULL);
	r_line[0] = '\0';
	r_line = ft_strjoin(r_line, buff_line);
	x = check_where_newline(r_line, '\n');
	while (res && x == -1)
	{
		res = read(fd, buff_line, BUFFER_SIZE);
		buff_line[res] = '\0';
		if (res <= 0 && !r_line[0])
		{
			free_mem(buff_line);
			free_mem(r_line);
			return (NULL);
		}
		r_line = ft_strjoin(r_line, buff_line);
		x = check_where_newline(buff_line, '\n');
	}
	return (r_line);
}

char	*check_data_in_buffer(char *line, char *buff_line)
{
	int		i;
	int		j;
	int		p;
	char	*s;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	p = 0;
	while (line[p])
	{
		if (p >= i)
			*buff_line++ = line[p++];
		else
			s[j++] = line[p++];
	}
	s[i] = '\0';
	*buff_line = '\0';
	free(line);
	return (s);
}

void	free_mem(char *str)
{
	// if (str[0] == '\0')
	// 	str[0] = 'Y';
	free (str);
	str = NULL;
}
