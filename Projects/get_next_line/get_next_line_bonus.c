/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:25:06 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/18 20:56:37 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	line = get_linex(&node->buffer);
	if (!line)
		return (delete_node(fd, &fd_nodes));
	return (line);
}

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

void	read_to_buffer(t_fd_buffer **node, int fd)
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
