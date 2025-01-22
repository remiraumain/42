/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:16:36 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/22 22:40:19 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_filename_valid(char *filename)
{
	unsigned int	len;

	len = ft_strlen(filename);
	return (!ft_strncmp(filename + (len - 4), ".ber", 4));
}

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
	char	*prefix;
	char	**map;
	char	*content;

	if (!is_filename_valid(filename))
		return (error("Invalid file extension. Expected: .ber"));
	prefix = ft_strdup("src/maps/");
	if (!prefix)
		return (error(""));
	path = ft_strjoin(prefix, filename);
	str_clear(prefix);
	if (!path)
		return (error(""));
	fd = open(path, O_RDONLY);
	str_clear(path);
	if (fd == -1)
		return (error("File not found. Place your map inside: ./maps/"));
	content = get_file_content(fd);
	map = ft_split(content, '\n');
	str_clear(content);
	close(fd);
	return (map);
}
