/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:21:13 by rraumain          #+#    #+#             */
/*   Updated: 2025/02/11 15:25:48 by rraumain         ###   ########.fr       */
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

void	set_neighbors(t_philo *philo, t_philo **left, t_philo **right)
{
	t_data	*data;
	int		id;

	data = philo->data;
	id = philo->id;
	if (id == 1)
	{
		*left = &data->philos[data->philo_count - 1];
		*right = &data->philos[1];
	}
	else if (id == data->philo_count)
	{
		*left = &data->philos[id - 2];
		*right = &data->philos[0];
	}
	else
	{
		*left = &data->philos[id - 2];
		*right = &data->philos[id];
	}
}

int	is_in_current_round(t_philo *philo, int current_round)
{
	if (philo->finished)
		return (0);
	if (current_round == 0 && (philo->id % 2) == 0)
		return (1);
	if (current_round == 1 && (philo->id % 2) == 1)
		return (1);
	return (0);
}

void	reset_ate_flags(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < data->philo_count)
	{
		philo = &data->philos[i];
		pthread_mutex_lock(&philo->data_mutex);
		if (is_in_current_round(philo, data->current_round))
			philo->ate_this_round = 0;
		pthread_mutex_unlock(&philo->data_mutex);
		i++;
	}
}
