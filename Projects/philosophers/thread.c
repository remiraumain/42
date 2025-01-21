/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:21:55 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/21 14:48:45 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*routine(void *arg)
{
	t_philo *philo;
	int		*running;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->is_running_mutex);
	running = &philo->data->is_running;
	pthread_mutex_unlock(&philo->data->is_running_mutex);
	if (philo->id % 2 == 0)
		usleep(philo->data->time_to_eat);
	while (*running)
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
		// printf("%ld %d meals eaten: %d\n", get_time_in_ms() - data->start_time, data->philos[i].id, data->philos[i].meals_eaten);
		if (data->philos[i].meals_eaten < data->nb_of_meals)
			return (1);
		i++;
	}
	return (0);
}

static void	monitor_routine(t_data *data)
{
	int		i;
	long	since_last_meal;
	int		*running;

	pthread_mutex_lock(&data->is_running_mutex);
	running = &data->is_running;
	pthread_mutex_unlock(&data->is_running_mutex);
    while (*running)
	{
		pthread_mutex_lock(&data->is_running_mutex);
		*running = has_eaten_enough(data);
		pthread_mutex_unlock(&data->is_running_mutex);
		i = 0;
		while (i < data->philo_count)
		{
			since_last_meal = get_time_in_ms() - data->philos[i].last_meal_time;
			if (since_last_meal > data->time_to_die)
			{
				pthread_mutex_lock(&data->print_mutex);
				printf("%ld %d died\n", get_time_in_ms() - data->start_time, data->philos[i].id);
				pthread_mutex_unlock(&data->print_mutex);
				pthread_mutex_lock(&data->is_running_mutex);
				*running = 0;
				pthread_mutex_unlock(&data->is_running_mutex);
				return ;
			}
			i++;
		}
		usleep(data->time_to_eat);
	}
}

int	create_threads(t_data *data)
{
	int		i;
	t_philo	philo;

	i = 0;
	data->start_time = get_time_in_ms();
	while (i < data->philo_count)
	{
		philo = data->philos[i];
        if (pthread_create(&data->philos[i].thread, NULL, routine, &data->philos[i]) != 0)
			return (my_error("an error occured while creating a philo thread"));
		i++;
	}
	monitor_routine(data);
	return (0);
}
