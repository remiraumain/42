/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:53:31 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/16 19:32:37 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_image(t_game data, t_pos pos, char tile, int size)
{
	void	*img;

	if (tile == '1')
		img = mlx_xpm_file_to_image(data.mlx, "textures/wall.xpm", \
			&size, &size);
	else if (tile == '0')
		img = mlx_xpm_file_to_image(data.mlx, "textures/floor.xpm", \
			&size, &size);
	else if (tile == 'C')
		img = mlx_xpm_file_to_image(data.mlx, "textures/collectible.xpm", \
			&size, &size);
	else if (tile == 'E')
		img = mlx_xpm_file_to_image(data.mlx, "textures/exit.xpm", \
			&size, &size);
	else if (tile == 'P')
		img = mlx_xpm_file_to_image(data.mlx, "textures/player.xpm", \
			&size, &size);
	else
		return ;
	mlx_put_image_to_window(data.mlx, data.win, img, \
		pos.x * size, pos.y * size);
	mlx_destroy_image(data.mlx, img);
}

void	render_map(t_game data, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			display_image(data, (t_pos){y, x}, map[y][x], data.size);
			x++;
		}
		y++;
	}
}
