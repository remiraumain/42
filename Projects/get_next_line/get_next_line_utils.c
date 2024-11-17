/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:51:20 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/17 19:37:57 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	current->next = *fd_nodes;
	*fd_nodes = current;
	return (current);
}

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

char *get_linex(char **buffer)
{
    char *line;
    size_t len;
    size_t i;

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

    i = 0;
    while (i < len)
    {
        line[i] = (*buffer)[i];
        i++;
    }
    line[i] = '\0';
    clean_buffer(buffer, len);
    return (line);
}

void read_to_buffer(char **buffer, int fd)
{
    ssize_t bytes_read;
    char *temp_buffer;
    size_t buffer_len;
    size_t i;

    temp_buffer = malloc(BUFFER_SIZE + 1);
    if (!temp_buffer)
        return;
    bytes_read = 0;
	while (!has_newline(*buffer) && (bytes_read = read(fd, temp_buffer, BUFFER_SIZE)) > 0)
    {
        temp_buffer[bytes_read] = '\0';
        buffer_len = ft_strclen(*buffer, '\0');
        *buffer = ft_realloc(*buffer, buffer_len + bytes_read + 1);
        if (!(*buffer))
        {
            free(temp_buffer);
            return;
        }
        i = 0;
        while (i < (size_t)bytes_read)
        {
            (*buffer)[buffer_len + i] = temp_buffer[i];
            i++;
        }
        (*buffer)[buffer_len + i] = '\0';
    }
    if (bytes_read == -1)
    {
        free(temp_buffer);
        return;
    }
    free(temp_buffer);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i = 0;
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

void clean_buffer(char **buffer, size_t len)
{
    size_t remaining_length;
    char *new_buffer;
	
	if ((*buffer)[len] == '\n')
	    len++;
    remaining_length = ft_strclen(*buffer + len, '\0');
    if (remaining_length == 0)
    {
        free(*buffer);
        *buffer = NULL;
		return;
    }
    new_buffer = malloc(remaining_length + 1);
    if (!new_buffer)
    {
        free(*buffer);
        *buffer = NULL;
		return;
    }
    ft_strlcpy(new_buffer, *buffer + len, remaining_length + 1);
    free(*buffer);
    *buffer = new_buffer;
}
void delete_node(int fd, t_fd_buffer **fd_nodes)
{
    t_fd_buffer *current;
    t_fd_buffer *prev;

    if (!fd_nodes || !*fd_nodes)
        return;
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
            return;
        }
        prev = current;
        current = current->next;
    }
}
