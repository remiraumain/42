/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:50:26 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/27 10:00:14 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philo.h"

//	String
unsigned int	my_strlen(char *string);
int				my_atoi(char *arg);

//	Cleanup
int				clear(t_data *data);

//	Error
int				my_error(char *message);

//	Time
long			get_time_in_ms(void);

#endif