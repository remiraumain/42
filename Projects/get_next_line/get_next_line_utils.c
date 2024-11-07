/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:51:20 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/07 14:36:48 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd_buffer	*get_node(int fd, t_fd_buffer **fd_nodes)
{
	t_fd_buffer	*node;
	
	node = malloc(sizeof(t_fd_buffer));
		if (!node)
			return (NULL);
	node->fd = fd;
	node->buffer = NULL;
	if (!(*fd_nodes))
		fd_nodes = &node;
	else
	{
		while ((*fd_nodes)->next != node && !((*fd_nodes)->next))
			*fd_nodes = (*fd_nodes)->next;
		(*fd_nodes)->next = node;
	}
	return (node);
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

char	*get_line(char *buffer)
{
	char	*line;
	size_t	len;
	size_t	i;
 
	if (has_newline(buffer))
		len = ft_strclen(buffer, '\n');
	else
		len = ft_strclen(buffer, '\0');
	if (!len)
		return (NULL);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	clean_buffer(buffer, len);
	return (line);
}

void	read_to_buffer(char	**buffer, int fd)
{
	ssize_t	bytes_read;
	char	*temp_buffer;
	size_t	buffer_len;
	size_t	i;	

	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return ;
	bytes_read = 0;
	while (!has_newline(*buffer) && !bytes_read)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp_buffer);
			return ;
		}
		buffer_len = ft_strclen(*buffer, '\0');
		*buffer = ft_realloc(*buffer, buffer_len + bytes_read);
		i = 0;
		while (i <= (buffer_len + bytes_read) && *buffer)
		{
			if (!(*buffer)[i])
				(*buffer)[i] = temp_buffer[i];
			i++;
		}
		(*buffer)[i] = '\0';
	}
	free(temp_buffer);
}

void	clean_buffer(char *buffer, size_t start)
{
	size_t	new_size;
	char	*temp_buffer;
	size_t	i;

	new_size = ft_strclen(&buffer[start], '\0');
	temp_buffer = malloc(new_size + 1);
	if (temp_buffer)
		return ;
	i = 0;
	while (i < new_size)
	{
		temp_buffer[i] = buffer[start + i];
		i++;
	}
	temp_buffer[i] = '\0';
	free(buffer);
	buffer = temp_buffer;
}
