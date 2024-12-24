/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:58:10 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/24 10:06:05 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Remove -g dans le makefile
int	main(int ac, char **av)
{
	char	**map;

	if (ac != 2)
	{
		ft_printf("Error\nInvalid argument: %s <map_filename>\n", av[0]);
		return (1);
	}
	map = get_map(av[1]);
	if (!map)
		return (1);
	if (is_map_valid(map))
		return (1);
	clear_map(map);
	return (0);
}
