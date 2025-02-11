/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:21:13 by rraumain          #+#    #+#             */
/*   Updated: 2025/02/11 12:59:28 by rraumain         ###   ########.fr       */
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

void	remove_id_from_array(int *array, int id)
{
	int	i;

	i = 0;
	while (array[i] != 0)
	{
		if (array[i] == id)
		{
			while (array[i] != 0)
			{
				array[i] = array[i + 1];
				i++;
			}
			return ;
		}
		i++;
	}
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

int	is_next_to_allowed(t_philo *philo)
{
	t_philo	*left_philo;
	t_philo	*right_philo;
	int		left_allowed;
	int		right_allowed;

	left_philo = NULL;
	right_philo = NULL;
	left_allowed = 0;
	right_allowed = 0;
	set_neighbors(philo, &left_philo, &right_philo);
	pthread_mutex_lock(&left_philo->data_mutex);
	left_allowed = left_philo->allowed;
	pthread_mutex_unlock(&left_philo->data_mutex);
	pthread_mutex_lock(&right_philo->data_mutex);
	right_allowed = right_philo->allowed;
	pthread_mutex_unlock(&right_philo->data_mutex);
	return (left_allowed || right_allowed);
}
