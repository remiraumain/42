/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:05:34 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/16 19:13:36 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move(t_game *data, int y, int x)
{
	t_pos	new_player_pos;

	if (data->map[data->player_pos.y + y][data->player_pos.x + x] == '1')
		return ;
	data->move_count++;
	ft_printf("Move count: %d\n", data->move_count);
	new_player_pos = (t_pos){data->player_pos.y + y, data->player_pos.x + x};
	if (data->map[new_player_pos.y][new_player_pos.x] == 'C')
		data->collected++;
	update_map(*data, new_player_pos, data->player_pos);
	data->player_pos = new_player_pos;
	if (data->total_collectible == data->collected && data->player_pos.x == data->exit_pos.x && data->player_pos.y == data->exit_pos.y)
		on_destroy(*data);
}

int	on_keypress(int keysym, t_game *data)
{
	if (keysym == 65362)
		move(data, -1, 0);
	else if (keysym == 65364)
		move(data, 1, 0);
	else if (keysym == 65363)
		move(data, 0, 1);
	else if (keysym == 65361)
		move(data, 0, -1);
	else if (keysym == 65307)
		on_destroy(*data);
	return (0);
}
