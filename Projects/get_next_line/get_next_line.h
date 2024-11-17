/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:25:02 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/17 19:03:23 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_fd_buffer
{
	int					fd;
	char				*buffer;
	struct s_fd_buffer	*next;
}	t_fd_buffer;

char		*get_next_line(int fd);
void		read_to_buffer(char **buffer, int fd);
t_fd_buffer	*get_node(int fd, t_fd_buffer **fd_nodes);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
//void		clean_node(t_fd_buffer *node, t_fd_buffer **fd_nodes);
void		clean_buffer(char **buffer, size_t start);
char		*get_linex(t_fd_buffer **node);
int			has_newline(char *buffer);
char	*ft_realloc(char *ptr, size_t new_size);
size_t		ft_strclen(char *s, char c);

#endif