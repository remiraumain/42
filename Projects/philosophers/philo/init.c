/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:41:39 by rraumain          #+#    #+#             */
/*   Updated: 2025/02/11 12:11:25 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	intit_philo(int i, t_philo *philo, t_data *data)
{
	philo->id = i + 1;
	philo->left_fork = &data->forks[i];
	philo->right_fork = &data->forks[(i + 1) % data->philo_count];
	philo->last_meal_time = 0;
	philo->meals_eaten = 0;
	philo->allowed = 0;
	philo->finished = 0;
	philo->data = data;
	if (pthread_mutex_init(&data->forks[i], NULL)
		|| pthread_mutex_init(&philo->data_mutex, NULL))
		return (1);
	return (0);
}

int	init(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
		return (clear(data));
	i = 0;
	while (i < data->philo_count)
	{
		if (intit_philo(i, &data->philos[i], data))
		{
			data->philo_count_init = i;
			return (clear(data));
		}
		i++;
	}
	data->philo_count_init = i;
	if (pthread_mutex_init(&data->print_mutex, NULL)
		|| pthread_mutex_init(&data->running_mutex, NULL))
	{
		data->philo_count_init = i;
		return (clear(data));
	}
	data->mutex_init = 1;
	return (0);
}
