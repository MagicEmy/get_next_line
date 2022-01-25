/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 18:15:56 by emlicame      #+#    #+#                 */
/*   Updated: 2022/01/25 17:42:29 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (dsize < d_len)
		return (dsize + s_len);
	else
	{
		dst = dst + d_len;
		ft_strlcpy(dst, src, dsize - d_len);
		return (d_len + s_len);
	}
}

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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		len;

	d = dst;
	s = src;
	len = ft_strlen(s);
	if (len + 1 < dstsize)
	{
		ft_memcpy(dst, src, len + 1);
	}
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		d[dstsize - 1] = '\0';
	}
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = src;
	d = dst;
	if (src == dst)
		return (NULL);
	while (n--)
	{
		*d++ = *s++;
	}
	return (dst);
}
