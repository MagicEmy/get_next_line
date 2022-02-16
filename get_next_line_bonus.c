/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 22:30:29 by ibulak        #+#    #+#                 */
/*   Updated: 2021/12/07 13:46:43 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
char	*get_line(char *str)
{
	int		i;
	char	*get_line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	get_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!get_line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		get_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		get_line[i] = str[i];
		i++;
	}
	get_line[i] = '\0';
	return (get_line);
}

char	*update_str(char *str)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	newstr = (char *)ft_calloc(sizeof(char), (ft_strlen(str) - i + 1));
	if (!newstr)
		return (NULL);
	j = 0;
	i++;
	while (str[i])
	{
		newstr[j] = str[i];
		j++;
		i++;
	}
	free(str);
	return (newstr);
}

char	*ft_read(char *str, int fd, int result)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (result != 0 && !ft_strchr(str, '\n'))
	{
		result = read(fd, buffer, BUFFER_SIZE);
		if (result < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[result] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free (buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1025];
	char		*line;
	int			result;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	result = 1;
	str[fd] = ft_read(str[fd], fd, result);
	if (!str[fd])
		return (NULL);
	line = get_line(str[fd]);
	str[fd] = update_str(str[fd]);
	if (line == NULL)
	{
		return (NULL);
		free (line);
	}
	if (result == 0)
		return (NULL);
	return (line);
}
