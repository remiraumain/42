/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:25:06 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/17 19:13:40 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd;
	char *line;

	fd = open("1char.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erreur on open");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_fd_buffer	*fd_nodes;
	t_fd_buffer			*node;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = get_node(fd, &fd_nodes);
	if (!node)
		return (NULL);
		
	if (!has_newline(node->buffer))
		read_to_buffer(&node->buffer, fd);

	line = get_linex(&node);
	if (!line)
		{
			if (!fd_nodes || !node)
				return (NULL);
			if (fd_nodes != node)
			{
				while (fd_nodes->next != node)
					fd_nodes = fd_nodes->next;
			}
			fd_nodes->next = node->next;
			free(node);
		}
	return (line);
}

char	*ft_realloc(char *ptr, size_t new_size)
{
	char	*new_ptr;

	if (!ptr)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	//new_ptr[0] = '\0';
	ft_strlcpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}

size_t	ft_strclen(char *s, char c)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}
