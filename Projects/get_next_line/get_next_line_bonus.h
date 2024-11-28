/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:40:48 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/28 22:55:30 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_fd_buffer
{
	int					fd;
	char				*buffer;
	ssize_t				bytes_read;
	struct s_fd_buffer	*next;
}						t_fd_buffer;

char		*get_next_line(int fd);
t_fd_buffer	*get_node(int fd, t_fd_buffer **fd_nodes);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			has_newline(char *buffer);
char		*ft_realloc(char *ptr, size_t new_size);
size_t		ft_strclen(char *s, char c);

#endif