/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 16:14:41 by emlicame      #+#    #+#                 */
/*   Updated: 2022/02/02 16:56:11 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;
	size_t	i;
	char	*new_string;

	i = 0;
	//if (!s1 && !s2)
	//	return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len + 1;
	new_string = (char *)malloc(sizeof(char) * total_len);
	if (!new_string)
		return (new_string);
	while (*s1)
		new_string[i++] = *s1++;
	while (*s2)
		new_string[i++] = *s2++;
	new_string[i] = '\0';
	return (new_string);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*dest;

	len = 0;
	while (s1[len])
		len++;
	dest = (char *) malloc (sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*string;
	unsigned int	i;
	size_t			j;

	i = start;
	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	string = (char *)malloc(len + 1);
	if (string == NULL)
		return (string);
	j = 0;
	while (s[i] && j < len)
	{
		string[j] = s[i];
		i++;
		j++;
	}
	string[j] = '\0';
	return (string);
}
