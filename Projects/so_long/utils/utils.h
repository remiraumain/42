/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:33:37 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/16 16:25:04 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

//	Error
void			*error(char *message);
int				error_int(char *message);

//	Cleanups
void			str_clear(char *s);
void			clear_map(char **map);
int				on_destroy(t_mlx data);

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

//	Controls
int				on_keypress(int keysym);
#endif