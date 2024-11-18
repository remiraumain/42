/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:51:20 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/18 21:27:39 by rraumain         ###   ########.fr       */
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
	current->bytes_read = 1;
	current->next = *fd_nodes;
	*fd_nodes = current;
	return (current);
}

char	*get_linex(char **buffer)
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

void	clean_buffer(char **buffer, size_t len)
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

void	*delete_node(int fd, t_fd_buffer **fd_nodes)
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
