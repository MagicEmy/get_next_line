/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 17:58:35 by emlicame      #+#    #+#                 */
/*   Updated: 2022/02/14 20:52:51 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buff_line;
	char		*build_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!buff_line)
		buff_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff_line)
		return (NULL);
	buff_line[0] = '\0';
	build_line = read_bytes(fd, buff_line);
	if (!build_line)
		return (NULL);
	//buff_line = check_data_in_buffer(build_line, buff_line);
	return (build_line);
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
	x = check_where_newline(buff_line, '\n');
	while (res && x == -1)
	{
		res = read(fd, buff_line, BUFFER_SIZE);
		if (res < 0)
		{
			free (buff_line);
			buff_line = NULL;
			return (0);
		}
		buff_line[res] = 0;
		r_line = ft_strjoin(r_line, buff_line);
		x = check_where_newline(buff_line, '\n');
	}
	if (r_line[0] == '\0')
	{
		free (r_line);
		r_line = NULL;
		return (0);
	}
	return (r_line);
}

char	*if_new_line(char *r_line, char *buff_line)
{
	char	*until_nl;
	int		x;

	x = check_where_newline(buff_line, '\n');
	until_nl = ft_substr(buff_line, 0, x + 2);
	r_line = ft_strjoin(r_line, until_nl);
	buff_line = ft_substr(buff_line, x + 2, BUFFER_SIZE - (x + 2));
	free (until_nl);
	return (r_line);
}
