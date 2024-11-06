/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:25:02 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/06 11:37:36 by rraumain         ###   ########.fr       */
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
	int			fd;
	char		*buffer;
	t_fd_buffer	*next;
}	t_fd_buffer;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);

#endif