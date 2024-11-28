/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:51:20 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/28 22:55:37 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Retrieve or create a buffer node for a given file descriptor.
 *
 * @param fd The file descriptor.
 * @param fd_nodes Double pointer to the head of the buffer nodes list.
 * @return Pointer to the corresponding buffer `node`, or `NULL` on failure.
 */
t_fd_buffer	*get_node(int fd, t_fd_buffer **fd_nodes)
{
	t_fd_buffer	*current;

	if (!fd_nodes)
		return (NULL);
	current = *fd_nodes;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	if (current)
		return (current);
	current = malloc(sizeof(t_fd_buffer));
	if (!current)
		return (NULL);
	current->fd = fd;
	current->buffer = NULL;
	current->bytes_read = 1;
	current->next = *fd_nodes;
	*fd_nodes = current;
	return (current);
}

/**
 * @brief Check if the buffer contains a newline character.
 *
 * @param buffer The string buffer to search.
 * @return `1` if a newline is found, `0` otherwise.
 */
int	has_newline(char *buffer)
{
	if (!buffer)
		return (0);
	while (*buffer)
	{
		if (*buffer == '\n')
			return (1);
		buffer++;
	}
	return (0);
}

/**
 * @brief Reallocate a memory block to a new size, copying existing data.
 *
 * @param ptr The original memory block.
 * @param new_size The size of the new memory block.
 * @return Pointer to the new memory block, or `NULL` on failure.
 */
char	*ft_realloc(char *ptr, size_t new_size)
{
	char	*new_ptr;

	if (!ptr)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (!new_ptr)
	{
		free(ptr);
		return (NULL);
	}
	ft_strlcpy(new_ptr, ptr, new_size + 1);
	free(ptr);
	return (new_ptr);
}

/**
 * @brief Copy a string to a destination buffer, ensuring NUL-termination.
 *
 * @param dst Destination buffer.
 * @param src Source string.
 * @param dstsize Size of the destination buffer.
 * @return The total length of the source string.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}

/**
 * @brief Compute the length of a string up to and including a specific
 * character.
 *
 * @param s The input string.
 * @param c The character to search for.
 * @return The length up to and including the character `c`, or the total
 * length if `c` is not found.
 */
size_t	ft_strclen(char *s, char c)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
	{
		if (s[len] == c)
			return (len + 1);
		len++;
	}
	return (len);
}
