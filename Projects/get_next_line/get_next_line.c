/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:25:06 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/07 14:33:47 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd;
	char *line;

	fd = open("hello.txt", O_RDONLY);
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

	node = get_node(fd, &fd_nodes);
	if (!node)
		return (NULL);
	if (!has_newline(node->buffer))
		read_to_buffer(&node->buffer, fd);
	line = get_line(node->buffer);
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

void	*ft_realloc(void *ptr, size_t size)
{
	void	*temp_ptr;
	size_t	i;			

	if (!ptr && size)
		return (ptr = malloc(size));
	else if (!size && ptr)
		free(ptr);
	else if (!ptr && !size)
		return (NULL);
	temp_ptr = malloc(sizeof(void *) * size);
	i = 0;
	while (i < size)
	{
		if (((char *)ptr)[i])
			((char *)temp_ptr)[i] = ((char *)ptr)[i];
		((char *)temp_ptr)[i] = 0;
		i++;
	}
	free(ptr);
	((char *)temp_ptr)[i] = 0;
	ptr = temp_ptr;
	return (ptr);
}

size_t	ft_strclen(char *s, char c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}
