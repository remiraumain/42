/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:17:01 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/19 15:58:01 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	str_clear(char *s)
{
	free(s);
	s = NULL;
}

char	*get_file_content(int fd)
{
	char	*line;
	char	*new_line;
	char	*tmp;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	new_line = line;
	while (new_line)
	{
		str_clear(new_line);
		new_line = get_next_line(fd);
		if (!new_line)
			return (line);
		tmp = line;
		line = ft_strjoin(line, new_line);
		str_clear(tmp);
	}
	return (line);
}

char	**get_map(char	*filename)
{
	int		fd;
	char	*path;
	char	*prefix;
	char	**map;

	prefix = ft_strdup("../maps/");
	if (!prefix)
		return (NULL);
	path = ft_strjoin(prefix, filename);
	str_clear(prefix);
	if (!path)
		return (NULL);
	fd = open(path, O_RDONLY);
	str_clear(path);
	if (fd == -1)
		return (NULL);
	map = ft_split(get_file_content(fd), '\n');
	return (map);
}
