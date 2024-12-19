/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanups.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:18:36 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/19 22:22:52 by rraumain         ###   ########.fr       */
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
		free(*map);
		*map = NULL;
		map++;
	}
	free(tmp);
}
