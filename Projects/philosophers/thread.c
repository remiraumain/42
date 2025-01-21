/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:21:55 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/21 11:23:16 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*routine(void *arg)
{
	t_philo *philo;
	int		running;

	philo = (t_philo *)arg;
	// pthread_mutex_lock(&philo->data->is_running);
	running = philo->data->is_running;
	// pthread_mutex_unlock(&philo->data->is_running);
	if (philo->id % 2 == 0)
		usleep(1000);
	while (running && philo->meals_eaten < philo->data->nb_of_meals)
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

static void	*monitor_routine(void *arg)
{
    t_data *data;
	int		i;
	long	since_last_meal;

	data = (t_data *)arg;
    while (data->is_running)
	{
		data->is_running = has_eaten_enough(data);
		i = 0;
		while (i < data->philo_count)
		{
			since_last_meal = get_time_in_ms() - data->philos[i].last_meal_time;
			if (since_last_meal > data->time_to_die)
			{
				pthread_mutex_lock(&data->print_mutex);
				printf("%ld %d died\n", get_time_in_ms(), data->philos[i].id);
				pthread_mutex_unlock(&data->print_mutex);
				data->is_running = 0;
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

int	create_threads(t_data *data)
{
	int		i;
	t_philo	philo;

	i = 0;
	while (i < data->philo_count)
	{
		philo = data->philos[i];
        if (pthread_create(&data->philos[i].thread, NULL, routine, &data->philos[i]) != 0)
			return (my_error("an error occured while creating a philo thread"));
		i++;
	}
	if (pthread_create(&data->monitoring_thread, NULL, monitor_routine, &data) != 0)
			return (my_error("an error occured while creating a monitoring thread"));
	return (0);
}
