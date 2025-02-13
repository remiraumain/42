/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:57:39 by rraumain          #+#    #+#             */
/*   Updated: 2025/02/12 20:01:02 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->thread_count_init)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

static void	clear_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count_init)
	{
		if (data->philos[i].philo_mutex_init == 1)
			pthread_mutex_destroy(&data->forks[i]);
		else if (data->philos[i].philo_mutex_init == 2)
		{
			pthread_mutex_destroy(&data->forks[i]);
			pthread_mutex_destroy(&data->philos[i].data_mutex);
		}
		i++;
	}
	if (data->mutex_init == 1)
		pthread_mutex_destroy(&data->print_mutex);
	else if (data->mutex_init == 2)
		pthread_mutex_destroy(&data->running_mutex);
}

static void	free_memory(t_data *data)
{
	free(data->philos);
	data->philos = NULL;
	free(data->forks);
	data->forks = NULL;
}

int	clear(t_data *data)
{
	if (!data)
		return (1);
	join_philosophers(data);
	clear_mutex(data);
	free_memory(data);
	memset(data, 0, sizeof(t_data));
	return (1);
}
