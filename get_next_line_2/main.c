/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 16:15:03 by emlicame      #+#    #+#                 */
/*   Updated: 2022/02/04 21:15:11 by emlicame      ########   odam.nl         */
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
	new_line = get_next_line(fd);
	printf ("%s", new_line);
	// while (new_line)
	// {
	// 	new_line = get_next_line(fd);
	// 	printf ("%s", new_line);
	// }
	//write(1, new_line, ft_strlen(new_line));
	close (fd);
	return (0);
}
