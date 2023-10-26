/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 16:15:03 by emlicame      #+#    #+#                 */
/*   Updated: 2023/10/26 14:15:54 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*filename;
	char	*new_line = (char *)0X1000;

	filename = "Makefile";
	fd = open (filename, O_RDONLY);
	// new_line = get_next_line(fd);
	// printf ("%s", new_line);
	// free (new_line);
	while (new_line)
	{
		new_line = get_next_line(fd);
		printf ("%s", new_line);
		free (new_line);
	}
	close (fd);
//	system ("leaks gnl");
	return (0);
}
