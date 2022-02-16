/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 22:30:34 by ibulak        #+#    #+#                 */
/*   Updated: 2021/12/07 13:42:08 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

char		*get_line(char *str);
char		*update_str(char *str);
char		*ft_read(char *str, int fd, int result);
char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *s);
char		*ft_strchr(char *s, int c);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);

#endif