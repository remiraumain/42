/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:33:37 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/16 19:32:44 by rraumain         ###   ########.fr       */
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
int				on_destroy(t_game data);

//	Map utils
unsigned int	map_height(char **map);
char			**dup_map(char **map);
unsigned int	count_collectible(char **map);
t_pos			find(char **map, char type);
void			update_map(t_game data, t_pos new_pos, t_pos old_pos);

//	Map init
char			**get_map(char	*filename);

//	Check collectible path
int				check_collectible_path(char **map);

//	Map validation
int				is_map_valid(char **map);

//	Controls
int				on_keypress(int keysym, t_game *data);

//	Render
void			display_image(t_game data, t_pos pos, char tile, int size);
void			render_map(t_game data, char **map);
#endif