/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 17:58:35 by emlicame      #+#    #+#                 */
/*   Updated: 2022/02/06 21:10:10 by emlicame      ########   odam.nl         */
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
	buff_line[BUFFER_SIZE] = '\0';
	build_line = read_the_buffer(fd, buff_line);
	if (!build_line)
		return (NULL);
	buff_line = ft_update_buffer(buff_line);
	return (build_line);
}

char	*read_the_buffer(int fd, char *buff_line)
{
	char		*r_line;
	char		*until_nl;
	ssize_t		res;
	int			x;

	res = 1;
	r_line = (char *)malloc((1) * sizeof(char));
	if (!r_line)
		return (NULL);
	*r_line = '\0';
	x = -1;
	while (res)
	{
		res = read(fd, buff_line, BUFFER_SIZE);
		x = check_where_newline(buff_line, '\n');
		if (x == -1)
			r_line = ft_strjoin(r_line, buff_line);
		else
		{
			until_nl = ft_substr(buff_line, 0, x + 1);
			r_line = ft_strjoin(r_line, until_nl);
			break ;
		}
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

char	*ft_update_buffer(char *buff_line)
{
	int		index;
	int		len;
	int		i;
	char	*temp;

	i = 0;
	index = check_where_newline(buff_line, '\n');
	len = BUFFER_SIZE - (index + 1);
	temp = ft_substr(buff_line, index, len + 1);
	buff_line = ft_substr(temp, 0, len + 1);
	free (temp);
	return (buff_line);
}
