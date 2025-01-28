/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:21:55 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/27 17:23:35 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(philo->data->time_to_eat * 1000);
	while (philo->data->is_running)
	{
		take_forks(philo);
		eat(philo);
		drop_forks(philo);
		sleep_and_think(philo);
	}
	return (NULL);
}

static int	has_eaten_enough(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		if (data->philos[i].meals_eaten < data->nb_of_meals)
			return (1);
		i++;
	}
	return (0);
}

static void	monitor_routine(t_data *data)
{
	int		i;

	while (data->is_running)
	{
		i = 0;
		pthread_mutex_lock(&data->print_mutex);
		while (i < data->philo_count)
		{
			if (get_time_in_ms() - data->philos[i].last_meal_time \
			> data->time_to_die)
			{
				if (data->is_running)
					printf("%ld %d died\n", get_time_in_ms() \
					- data->start_time, data->philos[i].id);
				data->is_running = 0;
				pthread_mutex_unlock(&data->print_mutex);
				return ;
			}
			i++;
		}
		pthread_mutex_unlock(&data->print_mutex);
		data->is_running = has_eaten_enough(data);
		usleep(1000);
	}
}

int	start_simu(t_data *data)
{
	int		i;

	i = 0;
	data->start_time = get_time_in_ms();
	while (i < data->philo_count)
	{
		if (pthread_create(&data->philos[i].thread, NULL, routine, \
		&data->philos[i]) != 0)
		{
			data->is_running = 0;
			
			return (my_error("an error occured while creating a philo thread"));
		}
		i++;
	}
	monitor_routine(data);
	return (0);
}
