/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 17:58:35 by emlicame      #+#    #+#                 */
/*   Updated: 2022/02/19 19:00:57 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line_index(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	return (i);
}

char	*check_data_in_buffer(char *line, char *buff_line)
{
	int		i;
	int		j;
	int		p;
	char	*s;

	j = 0;
	i = new_line_index(line);
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

char	*test(char **s1, char **s2)
{
	free(*s1);
	free(*s2);
	return (NULL);
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
		if (res >= 0)
		{
			buff_line[res] = '\0';
			r_line = ft_strjoin(r_line, buff_line);
			x = check_where_newline(buff_line, '\n');
		}
		if (res <= 0 && !r_line[0])
			return (test(&buff_line, &r_line));
	}
	return (r_line);
}

char	*get_next_line(int fd)
{
	static char	*buff_line;
	char		*line;

	if (read(fd, NULL, 0) == -1 || BUFFER_SIZE < 1)
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
	{
		buff_line = NULL;
		return (NULL);
	}
	line = check_data_in_buffer(line, buff_line);
	if (!line)
		return (NULL);
	return (line);
}
