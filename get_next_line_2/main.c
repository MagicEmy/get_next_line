/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 16:15:03 by emlicame      #+#    #+#                 */
/*   Updated: 2022/02/06 21:10:27 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*filename;
	char	*new_line;

	i = 0;
	filename = "Text.txt";
	fd = open (filename, O_RDONLY);
	// while (i < 5)
	// {
	// 	printf ("Go");
	// 	new_line = get_next_line(fd);
	// 	printf ("%s", new_line);
	// 	i++;
	// }
	new_line = get_next_line(fd);
	write(1, new_line, ft_strlen(new_line));
	close (fd);
	return (0);
}
