/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 16:13:10 by emlicame      #+#    #+#                 */
/*   Updated: 2022/02/04 21:30:12 by emlicame      ########   odam.nl         */
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
	build_line = (char *)malloc(1 * sizeof(char));
	if (!build_line)
		return (NULL);
	build_line[0] = '\0';
	buff_line = read_the_buffer(fd, buff_line);
	if (!build_line)
		return (NULL);
	build_line = ft_strjoin(build_line, buff_line);
	return (build_line);
}

char	*read_the_buffer(int fd, char *buff_line)
{
	ssize_t	res;
	char	*r_line;
	int		x;
//	char	*new_line;

	res = 1;
	r_line = (char *)malloc((1) * sizeof(char));
	if (!r_line)
		return (NULL);
	*r_line = '\0';
	while (res)
	{
		res = read(fd, buff_line, BUFFER_SIZE);
		if (res == -1)
			return (NULL);
		x = check_where_newline(buff_line, '\n');
		if (x != -1)
			break ;
		r_line = ft_strjoin(r_line, buff_line);
		// 	new_line = ft_is_new_line(buff_line);
		// 	r_line = ft_strjoin(r_line, new_line);
		// 	free(new_line);		
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

// // char	*ft_is_new_line(char *buff_line)
// // {
// // 	int		index;
// // 	char	*temp;
// // 	char	*part;
// // 	int		i;
// // 	int		z;

// // 	i = 0;
// // 	z = 0;
// // 	index = 0;
// // 	index = check_where_newline(buff_line, '\n');
// // 	temp = (char *)malloc(index + 1 * sizeof(char));
// // 	part = malloc ((index + 1) * sizeof(char));
// // 	while (i < index)
// // 	{
// // 		temp[i] = buff_line[i];
// // 		i++;
// // 	}
// // 	temp[index] = '\0';
// // 	ft_memmove(part, temp, index);
// // 	while (buff_line[z + index])
// // 	{
// // 		temp[z] = buff_line[z + index];
// // 		z++;
// // 	}
// // 	temp[z] = '\0';
// // 	ft_memmove(buff_line, temp, z);
// // 	free (temp);
// // 	return (part);
// // }
