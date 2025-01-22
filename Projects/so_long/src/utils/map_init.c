/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:16:36 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/23 00:20:32 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*get_file_content(int fd)
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
		if (line != new_line)
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
	char	**map;
	char	*content;

	path = ft_strjoin("src/maps/", filename);
	if (!path)
		return (error("Allocation failed"));
	fd = open(path, O_RDONLY);
	str_clear(path);
	if (fd == -1)
		return (error("Map file not found"));
	content = get_file_content(fd);
	map = ft_split(content, '\n');
	str_clear(content);
	close(fd);
	if (!map)
		return (error("Invalid map"));
	return (map);
}
