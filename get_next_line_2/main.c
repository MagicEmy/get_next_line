/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 16:15:03 by emlicame      #+#    #+#                 */
/*   Updated: 2022/02/01 16:17:53 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*filename;

	filename = "Text.txt";
	fd = open (filename, O_RDONLY);
	get_next_line(fd);
	close (fd);
	return (0);
}
