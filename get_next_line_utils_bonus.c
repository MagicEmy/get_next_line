/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 22:30:40 by ibulak        #+#    #+#                 */
/*   Updated: 2021/12/02 11:56:18 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while (len > 0)
	{
		str[len - 1] = c;
		len--;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*s;

	total = count * size;
	s = (void *) malloc (total);
	if (!s)
		return (0);
	ft_memset (s, 0, total);
	return (s);
}

size_t	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	if (!s)
		return (0);
	while (!(s[n] == '\0'))
		n++;
	return (n);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s != '\0' && (char)c != *s)
		s++;
	if (*s == (char) c)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*s_join;

	if (!s1)
		s1 = (char *)ft_calloc(sizeof(char), 1);
	if (!s1 || !s2)
		return (NULL);
	s_join = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s_join == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s_join[i] = s1[i];
		i++;
	}
	while (*s2 != '\0')
	{
		s_join[i] = *s2;
		i++;
		s2++;
	}
	free(s1);
	return (s_join);
}
