/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:33:57 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/17 12:59:37 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(char **map)
{
	t_game	data;

	data.size = 128;
	data.mlx = mlx_init();
	if (!data.mlx)
		return ;
	data.map = map;
	data.exit_pos = find(map, 'E');
	data.player_pos = find(map, 'P');
	data.total_collectible = count_collectible(map);
	data.collected = 0;
	data.move_count = 0;
	data.win = mlx_new_window(data.mlx, ft_strlen(map[0]) \
		* data.size, map_height(map) * data.size, "so_long");
	render_map(data, map);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx);
}
