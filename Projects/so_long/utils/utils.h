/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:33:37 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/24 10:22:35 by rraumain         ###   ########.fr       */
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

//	Cleanups
void	str_clear(char *s);
void	clear_map(char **map);

//	Error
void	*error(char *message);

//	Map init
char	**get_map(char	*filename);

//	Map validation
int		is_map_valid(char **map);

#endif