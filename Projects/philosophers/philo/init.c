/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:41:39 by rraumain          #+#    #+#             */
/*   Updated: 2025/02/13 13:24:20 by rraumain         ###   ########.fr       */
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
	philo->ate_this_round = 0;
	philo->finished = 0;
	philo->thinking = 0;
	philo->data = data;
	if (pthread_mutex_init(&data->forks[i], NULL))
	{
		philo->philo_mutex_init = 0;
		return (1);
	}
	if (pthread_mutex_init(&philo->data_mutex, NULL))
	{
		philo->philo_mutex_init = 1;
		return (1);
	}
	philo->philo_mutex_init = 2;
	return (0);
}

static int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		if (intit_philo(i, &data->philos[i], data))
		{
			data->philo_count_init = i;
			clear(data);
			return (1);
		}
		i++;
	}
	data->philo_count_init = i;
	return (0);
}

static int	init_data_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->print_mutex, NULL))
	{
		data->mutex_init = 0;
		clear(data);
		return (1);
	}
	if (pthread_mutex_init(&data->running_mutex, NULL))
	{
		data->mutex_init = 1;
		clear(data);
		return (1);
	}
	data->mutex_init = 2;
	data->thread_count_init = 0;
	return (0);
}

int	init(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		return (1);
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
	{
		free(data->forks);
		data->forks = NULL;
		return (1);
	}
	if (init_philos(data))
		return (1);
	if (init_data_mutex(data))
		return (1);
	return (0);
}
