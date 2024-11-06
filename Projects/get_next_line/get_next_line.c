/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:25:06 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/06 11:39:35 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Calculate the length of a string.
 *
 * Calculates the length of the string pointed to by `s`, excluding the
 * terminating null byte (`\0`).
 *
 * @param s Pointer of the string.
 * @return The lenght of the string (number of bytes) pointed by `s`.
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/**
 * @brief Copy a string to another with size limit.
 *
 * Copy up to `dstsize - 1` characters from the NUL-terminated string `src` to
 * `dst`, NUL-terminating the result.
 *
 * @param dst The destination string to copy to.
 * @param src The source string to copy.
 * @param dstsize The total size of the destination buffer.
 * @return The length of `src`.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		if (i < dstsize)
			dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	else
		dst[dstsize - 1] = '\0';
	return (i);
}

/**
 * @brief Append a string to another with size limit.
 *
 * Appends the null-terminated string `src` to the end of `dst`, ensuring
 * that the total length does not exceed `size` (including the null terminator).
 * If `size` is less than or equal to the length of `dst`, `dst` is left
 * unchanged, and `size + srclen` is returned.
 *
 * @param dst The destination string to append to.
 * @param src The source string to append.
 * @param dstsize The total size of the destination buffer.
 * @return The initial length of `dst` plus the length of `src`.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!dstsize)
		return (srclen);
	dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	if (dstsize > dstlen + 1)
		ft_strlcpy(dst + dstlen, src, dstsize - dstlen);
	return (dstlen + srclen);
}

/**
 * @brief Return the concatenated string.
 *
 * Allocates (with malloc(3)) and returns a new string, which is the result of
 * the concatenation of `s1` and `s2`.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. `NULL` if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned long	len;
	char			*res;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc((len) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len);
	ft_strlcat(res, s2, len);
	return (res);
}

char	*get_next_line(int fd)
{
	static t_fd_buffer	**fd_nodes;
	t_fd_buffer			*node;
	ssize_t				bytes_read;
	char				*temp_buffer;
	char				*line;

	node = get_node(fd, fd_nodes);
	if (!node)
		return (NULL);
	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (temp_buffer)
		return (NULL);
	temp_buffer[bytes_read] = '\0';
	bytes_read = 0;
	while (!has_line(node->buffer) && !bytes_read)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp_buffer);
			return (NULL);
		}
		ft_strjoin(node->buffer, temp_buffer);
	}
	free(temp_buffer);
	line = getline(node->buffer);
	if (!bytes_read && !line)
	{
		del_node(node);
		return (NULL);
	}
	return (line);
}
