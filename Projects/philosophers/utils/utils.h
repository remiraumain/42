/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:50:26 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/16 23:50:39 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../philo.h"

//	String
unsigned int	my_strlen(char *string);
int				my_atoi(char *arg);

//	Error
int				my_error(char *message);

//	Parse
int				parse(int ac, char **av, t_data *data);

#endif