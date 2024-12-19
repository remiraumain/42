/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:25:06 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/28 22:55:39 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Read from a file descriptor into the node's buffer until a newline or
 * EOF is encountered.
 *
 * @param node Double pointer to the file descriptor buffer node.
 * @param fd The file descriptor to read from.
 */
static void	read_to_buffer(t_fd_buffer **node, int fd)
{
	char	*temp_buffer;
	size_t	buffer_len;

	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return ;
	temp_buffer[0] = '\0';
	while (!has_newline(temp_buffer) && (*node)->bytes_read > 0)
	{
		(*node)->bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if ((*node)->bytes_read == -1)
			return (free(temp_buffer));
		temp_buffer[(*node)->bytes_read] = '\0';
		buffer_len = ft_strclen((*node)->buffer, '\0');
		(*node)->buffer = ft_realloc((*node)->buffer, buffer_len
				+ (*node)->bytes_read + 1);
		if (!(*node)->buffer)
			return (free(temp_buffer));
		ft_strlcpy(&(*node)->buffer[buffer_len], temp_buffer,
			(*node)->bytes_read + 1);
	}
	free(temp_buffer);
}

/**
 * @brief Clean the buffer by removing the first len bytes and updating it.
 *
 * @param buffer Double pointer to the buffer to be cleaned.
 * @param len The number of bytes to remove from the beginning of the buffer.
 */
static void	clean_buffer(char **buffer, size_t len)
{
	size_t	remaining_length;
	char	*new_buffer;

	remaining_length = ft_strclen(*buffer + len, '\0');
	if (remaining_length == 0)
	{
		free(*buffer);
		*buffer = NULL;
		return ;
	}
	new_buffer = malloc(remaining_length + 1);
	if (!new_buffer)
	{
		free(*buffer);
		*buffer = NULL;
		return ;
	}
	ft_strlcpy(new_buffer, *buffer + len, remaining_length + 1);
	free(*buffer);
	*buffer = new_buffer;
}

/**
 * @brief Extract a line from the buffer up to a newline or the end of the
 * string.
 *
 * @param buffer Double pointer to the buffer containing the data.
 * @return Pointer to the extracted `line`, or `NULL` if no line is available or
 * on failure.
 */
static char	*get_line(char **buffer)
{
	char	*line;
	size_t	len;

	if (buffer == NULL || *buffer == NULL)
		return (NULL);
	if (has_newline(*buffer))
		len = ft_strclen(*buffer, '\n');
	else
		len = ft_strclen(*buffer, '\0');
	if (len == 0)
		return (NULL);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, *buffer, len + 1);
	clean_buffer(buffer, len);
	return (line);
}

/**
 * @brief Delete the buffer node associated with a given file
 * descriptor.
 *
 * @param fd The file descriptor of the node to delete.
 * @param fd_nodes Double pointer to the head of the buffer nodes list.
 * @return `NULL` after deletion.
 */
static void	*delete_node(int fd, t_fd_buffer **fd_nodes)
{
	t_fd_buffer	*current;
	t_fd_buffer	*prev;

	if (!fd_nodes || !*fd_nodes)
		return (NULL);
	current = *fd_nodes;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (prev)
				prev->next = current->next;
			else
				*fd_nodes = current->next;
			if (current->buffer)
				free(current->buffer);
			free(current);
			return (NULL);
		}
		prev = current;
		current = current->next;
	}
	return (NULL);
}

/**
 * @brief Read and return the next line from a file descriptor.
 *
 * This is the main function of the `get_next_line` project.
 *
 * @param fd The file descriptor to read from.
 * @return The next line as a dynamically allocated `string`, or `NULL` on error
 * or EOF.
 */
char	*get_next_line(int fd)
{
	static t_fd_buffer	*fd_nodes;
	t_fd_buffer			*node;
	char				*line;
	int					newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = get_node(fd, &fd_nodes);
	if (!node)
		return (NULL);
	newline = has_newline(node->buffer);
	if (!newline && node->bytes_read > 0)
	{
		read_to_buffer(&node, fd);
		if (node->bytes_read == -1)
			return (delete_node(fd, &fd_nodes));
	}
	line = get_line(&node->buffer);
	if (!line)
		return (delete_node(fd, &fd_nodes));
	return (line);
}
