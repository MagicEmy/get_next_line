/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 16:15:03 by emlicame      #+#    #+#                 */
/*   Updated: 2022/02/03 16:55:14 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*filename;
	char	*new_line;
	int		i;

	filename = "Text.txt";
	i = 0;
	fd = open (filename, O_RDONLY);
	while (i < 100)
	{
		new_line = get_next_line(fd);
		printf ("%s", new_line);
		free(new_line);
		i++;
	}
	//write(1, new_line, ft_strlen(new_line));
	close (fd);
	return (0);
}
