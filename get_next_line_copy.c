/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 17:58:35 by emlicame      #+#    #+#                 */
/*   Updated: 2022/02/07 22:15:49 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *strdub(char *str)
{
	int i = 0;
	char * res = malloc(ft_strlen(str));
	while(*str)
		res[i++] = *str++;
	res[i] = 0;
	return res;
}

char	*get_next_line(int fd)
{
	static t_data	data;
	int index;

	data.fd = fd;
	if (data.fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!data.buff_line)
		data.buff_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	else
		data.build_line = strdub(data.buff_line);
	if (!data.buff_line)
		return (NULL);
	
	data.build_line = read_the_buffer(&data);
	if (!data.build_line)
		return (NULL);
	index = check_where_newline(data.buff_line, '\n');
	data.buff_line = ft_substr(data.buff_line, index + 1, ft_strlen(&data.buff_line[index + 1]));
	return (data.build_line);
}
// if (buff_line != NULL && (ft_strlen(buff_line) > 0))
// 		r_line = ft_strjoin(r_line, buff_line);


char	*read_the_buffer(t_data *data)
{
	ssize_t		res;

	res = 1;
	if (!data->build_line)
	{
		data->build_line = (char *)malloc((1) * sizeof(char));
		if (!data->build_line)
			return (NULL);
		*data->build_line = '\0';
	}
	while (res)
	{
		res = read(data->fd, data->buff_line, BUFFER_SIZE);
		data->buff_line[res] = '\0';
		data->buff_line[BUFFER_SIZE] = 0;
		if (check_where_newline(data->buff_line, '\n') == -1)
			data->build_line = ft_strjoin(data->build_line, data->buff_line);
		else
		{
			data->build_line = if_new_line(data->build_line, data->buff_line);
			break ;
		}
	}
	if (!res)
		return (0);
	return (data->build_line);
}

char	*if_new_line(char *r_line, char *buff_line)
{
	int		x;
	char	*until_nl;

	
	x = check_where_newline(buff_line, '\n');
	until_nl = ft_substr(buff_line, 0, x + 1);
	r_line = ft_strjoin(r_line, until_nl);
	free (until_nl);
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
//if index -1 return buff_line
	i = 0;
	index = check_where_newline(buff_line, '\n');
	len = BUFFER_SIZE - (index + 1);
	temp = ft_substr(buff_line, index, len + 1);
	buff_line = ft_substr(temp, 0, len + 1);
	free (temp);
	return (buff_line);
}
