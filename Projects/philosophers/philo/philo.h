/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:51:37 by rraumain          #+#    #+#             */
/*   Updated: 2025/02/13 12:16:35 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <string.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include "struct.h"
# include "utils.h"

int		parse(int ac, char **av, t_data *data);
int		init(t_data *data);
void	simulation(t_data *data);
//	ACTIONS
void	take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);
void	eat(t_philo *philo);
void	psleep(t_philo *philo);
void	think(t_philo *philo);
void	died(t_philo *philo);
void	print_action(t_philo *philo, char *action);

#endif