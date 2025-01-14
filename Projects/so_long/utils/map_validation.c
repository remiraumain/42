/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:16:19 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/14 17:47:01 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_lines_size(char **map)
{
	unsigned int	ref_size;
	unsigned int	i;

	ref_size = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ref_size != ft_strlen(map[i]))
			return (1);
		i++;
	}
	if (i < 3)
		return (1);
	return (0);
}

static int	check_walls_arround(char **map)
{
	unsigned int	ref_size;
	unsigned int	last_line;
	unsigned int	line;
	unsigned int	i;

	ref_size = ft_strlen(map[0]);
	last_line = 0;
	while (map[last_line])
		last_line++;
	last_line--;
	line = 0;
	while (map[line])
	{
		i = 0;
		while ((line == last_line || line == 0) && map[line][i] == '1')
			i++;
		while (!(line == last_line || line == 0) && map[line][0] == '1'
			&& map[line][ref_size - 1] == '1' && map[line][i])
			i++;
		if (i != ref_size)
			return (1);
		line++;
	}
	return (0);
}

static int	check_allowed_values(char **map)
{
	unsigned int	i;

	while (*map)
	{
		i = 0;
		while ((*map)[i])
		{
			if ((*map)[i] != 'P' && (*map)[i] != 'E'
				&& (*map)[i] != 'C' && (*map)[i] != '1'
				&& (*map)[i] != '0')
				return (1);
			i++;
		}
		map++;
	}
	return (0);
}

static int	check_entities(char **map)
{
	t_entities		entities;
	unsigned int	i;
	unsigned int	line;

	ft_memset(&entities, 0, sizeof entities);
	line = 0;
	while (map[line])
	{
		i = 0;
		while (map[line][i])
		{
			if (map[line][i] == 'P')
				entities.p++;
			else if (map[line][i] == 'E')
				entities.e++;
			else if (map[line][i] == 'C')
				entities.c++;
			i++;
		}
		line++;
	}
	if (!(entities.p == 1 && entities.e == 1 && entities.c > 0))
		return (1);
	return (0);
}

// check_collectible_path
int	is_map_valid(char **map)
{
	if (check_lines_size(map))
	{
		error("Invalid map. Inconsistant map lien length");
		return (1);
	}
	if (check_walls_arround(map))
	{
		error("Invalid map. Walls (1) shoudl be at every border");
		return (1);
	}
	if (check_allowed_values(map))
	{
		error("Invalid map. Illegal character");
		return (1);
	}
	if (check_entities(map))
	{
		error("Invalid map. Only 1 Player, 1 Exit and at least 1 Collectible");
		return (1);
	}
	return (0);
}
