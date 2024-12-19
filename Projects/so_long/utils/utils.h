/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:33:37 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/19 22:23:57 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

//	Cleanups
void	str_clear(char *s);
void	clear_map(char **map);

//	Error
void	*error(char *message);

//	Map init
char	**get_map(char	*filename);

#endif