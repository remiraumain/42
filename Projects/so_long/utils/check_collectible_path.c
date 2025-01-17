/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collectible_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:35:02 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/17 07:23:10 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static unsigned int	count_cells(char **map)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (map[row])
		row++;
	col = ft_strlen(map[0]);
	return (row * col);
}

static void	flood_fill(char **map, t_pos player_pos, unsigned int cells)
{
	unsigned int	top;
	t_pos			*queue;
	t_pos			current;

	queue = malloc(cells * sizeof(t_pos));
	if (!queue)
		return ;
	top = 0;
	queue[top++] = player_pos;
	while (top)
	{
		current = queue[--top];
		if (map[current.y][current.x] != '1')
		{
			map[current.y][current.x] = '1';
			queue[top++] = (t_pos){current.y - 1, current.x};
			queue[top++] = (t_pos){current.y + 1, current.x};
			queue[top++] = (t_pos){current.y, current.x - 1};
			queue[top++] = (t_pos){current.y, current.x + 1};
		}
	}
	free(queue);
	queue = NULL;
}

int	check_collectible_path(char **map)
{
	char			***dup;
	unsigned int	invalid_collectible;

	dup = malloc(sizeof(char ***));
	if (!dup)
		return (0);
	*dup = dup_map(map);
	flood_fill(*dup, find(map, 'P'), count_cells(map));
	invalid_collectible = count_collectible(*dup);
	clear_map(*dup);
	free(dup);
	if (invalid_collectible)
		return (1);
	return (0);
}
