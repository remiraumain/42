/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:23:38 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/16 16:25:16 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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

typedef struct s_mlx
{
	void *mlx;
	void *win;
}	t_mlx;

#endif