/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:58:10 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/19 15:58:42 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char	**map;
	
	if (ac != 2)
	{
		ft_printf("Error\nInvalid argument, expected: %s <map_filename>\n", av[0]);
		return (1);
	}
	map = get_map(av[1]);
	clear_map(map);
	return (0);
}
