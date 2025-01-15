/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:49:26 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/15 11:22:13 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**dup_map(char **map)
{
	unsigned int	i;
	unsigned int	row;
	char			**dup;

	if (!map)
		return (NULL);
	row = 0;
	while (map[row])
		row++;
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

t_pos	find_player(char **map)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				return ((t_pos){y, x});
			x++;
		}
		y++;
	}
	return ((t_pos){0, 0});
}
