/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:33:37 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/15 11:22:41 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_entities
{
	unsigned int	p;
	unsigned int	e;
	unsigned int	c;
}	t_entities;

typedef struct s_pos
{
	unsigned int	y;
	unsigned int	x;
}	t_pos;

//	Error
void			*error(char *message);
int				error_int(char *message);

//	Cleanups
void			str_clear(char *s);
void			clear_map(char **map);

//	Map utils
char			**dup_map(char **map);
unsigned int	count_collectible(char **map);
t_pos			find_player(char **map);

//	Map init
char			**get_map(char	*filename);

//	Check collectible path
int				check_collectible_path(char **map);

//	Map validation
int				is_map_valid(char **map);
#endif