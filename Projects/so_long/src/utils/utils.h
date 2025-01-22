/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:33:37 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/22 23:04:35 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

//	Check collectible path
int				check_collectible_path(char **map);

//	Cleanups
void			str_clear(char *s);
void			clear_map(char **map);
int				on_destroy(t_game *data);

//	Controls
int				on_keypress(int keysym, t_game *data);

//	Error
void			*error(char *message);
int				error_int(char *message);

//	Map init
char			**get_map(char	*filename);

//	Map utils
unsigned int	map_height(char **map);
char			**dup_map(char **map);
unsigned int	count_collectible(char **map);
t_pos			find(char **map, char type);
void			update_map(t_game data, t_pos new_pos, t_pos old_pos);

//	Map validation
int				is_map_valid(char **map);

//	Parse arg
int				parse_arg(char *arg);

//	Render
void			display_image(t_game data, t_pos pos, char tile, int size);
void			render_map(t_game data, char **map);

#endif