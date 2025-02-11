/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:50:26 by rraumain          #+#    #+#             */
/*   Updated: 2025/02/11 15:28:23 by rraumain         ###   ########.fr       */
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

//	Extra
void			died(t_philo *philo);
void			set_neighbors(t_philo *philo, t_philo **left, t_philo **right);
int				is_in_current_round(t_philo *philo, int current_round);
void			reset_ate_flags(t_data *data);

//	Priority
void			round_update(t_data *data);

#endif