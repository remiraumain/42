/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:10:09 by rraumain          #+#    #+#             */
/*   Updated: 2025/02/13 12:12:30 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	died(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->running_mutex);
	data->is_running = 0;
	pthread_mutex_unlock(&data->running_mutex);
	pthread_mutex_lock(&data->print_mutex);
	printf("%ld %d died\n", get_time_in_ms() - data->start_time, philo->id);
	pthread_mutex_unlock(&data->print_mutex);
}

void	print_action(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	pthread_mutex_lock(&philo->data->running_mutex);
	if (philo->data->is_running)
		printf("%ld %d %s\n", get_time_in_ms() \
		- philo->data->start_time, philo->id, action);
	pthread_mutex_unlock(&philo->data->running_mutex);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
