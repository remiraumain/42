/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanups.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:18:36 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/16 16:21:41 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	str_clear(char *s)
{
	free(s);
	s = NULL;
}

void	clear_map(char **map)
{
	char	**tmp;

	tmp = map;
	while (*map)
	{
		str_clear(*map);
		map++;
	}
	free(tmp);
}

int	on_destroy(t_mlx data)
{
	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	exit(0);
	return (0);
}
