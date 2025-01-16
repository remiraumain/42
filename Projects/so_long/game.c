/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:33:57 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/16 16:21:28 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_image(void *mlx, void *win, t_pos pos, char tile, int size)
{
	void	*img;

	if (tile == '1')
		img = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &size, &size);
	else if (tile == '0')
		img = mlx_xpm_file_to_image(mlx, "textures/floor.xpm", &size, &size);
	else if (tile == 'C')
		img = mlx_xpm_file_to_image(mlx, "textures/collectible.xpm", &size, &size);
	else if (tile == 'E')
		img = mlx_xpm_file_to_image(mlx, "textures/exit.xpm", &size, &size);
	else if (tile == 'P')
		img = mlx_xpm_file_to_image(mlx, "textures/player.xpm", &size, &size);
	else
		return ;
	mlx_put_image_to_window(mlx, win, img, pos.x * size, pos.y * size);
	mlx_destroy_image(mlx, img);
}

void	render_map(void *mlx, void *win, char **map, int size)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			display_image(mlx, win, (t_pos){y, x}, map[y][x], size);
			x++;
		}
		y++;
	}
}

void	start_game(char **map)
{
	t_mlx	data;
	int		size;
	unsigned int	row;
	
	row = 0;
	while (map[row])
		row++;
	size = 32 *4;
	data.mlx = mlx_init();
	if (!data.mlx)
		return ;
	data.win = mlx_new_window(data.mlx, ft_strlen(map[0]) * size, row * size, "so_long");
	render_map(data.mlx, data.win, map, size);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &on_keypress, (void *){""});
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx);
}