/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:49:26 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/16 19:29:45 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

unsigned int	map_height(char **map)
{
	unsigned int	row;

	row = 0;
	while (map[row])
		row++;
	return (row);
}

char	**dup_map(char **map)
{
	unsigned int	i;
	unsigned int	row;
	char			**dup;

	if (!map)
		return (NULL);
	row = map_height(map);
	dup = malloc((row + 1) * sizeof(char *));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < row)
	{
		dup[i] = ft_strdup(map[i]);
		if (!dup[i])
		{
			clear_map(dup);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

unsigned int	count_collectible(char **map)
{
	unsigned int	count;
	unsigned int	i;
	unsigned int	j;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_pos	find(char **map, char type)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == type)
				return ((t_pos){y, x});
			x++;
		}
		y++;
	}
	return ((t_pos){0, 0});
}

void	update_map(t_game data, t_pos new_pos, t_pos old_pos)
{
	data.map[new_pos.y][new_pos.x] = 'P';
	display_image(data, new_pos, 'P', data.size);
	if (old_pos.x == data.exit_pos.x && old_pos.y == data.exit_pos.y)
	{
		data.map[old_pos.y][old_pos.x] = 'E';
		display_image(data, old_pos, 'E', data.size);
	}
	else
	{
		data.map[old_pos.y][old_pos.x] = '0';
		display_image(data, old_pos, '0', data.size);
	}
}
