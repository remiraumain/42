/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:21:55 by rraumain          #+#    #+#             */
/*   Updated: 2025/02/11 12:14:21 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	actions(t_philo *philo)
{
	take_forks(philo);
	eat(philo);
	drop_forks(philo);
	sleep_and_think(philo);
}

static void	*routine(void *arg)
{
	t_philo	*philo;
	int		running;
	int		finished;
	int		allowed;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->data->running_mutex);
		running = philo->data->is_running;
		pthread_mutex_unlock(&philo->data->running_mutex);
		pthread_mutex_lock(&philo->data_mutex);
		finished = philo->finished;
		allowed = philo->allowed;
		pthread_mutex_unlock(&philo->data_mutex);
		if (!running || finished)
			return (NULL);
		if (allowed)
			actions(philo);
		usleep(500);
	}
}

static void	check_philos(t_data *data, int *finished_count)
{
	int		i;
	int		finished;
	long	last_meal_time;
	t_philo	*philo;

	i = 0;
	while (i < data->philo_count)
	{
		philo = &data->philos[i];
		pthread_mutex_lock(&philo->data_mutex);
		finished = philo->finished;
		last_meal_time = get_time_in_ms() - philo->last_meal_time;
		pthread_mutex_unlock(&philo->data_mutex);
		if (finished)
			(*finished_count)++;
		else
		{
			if (last_meal_time >= data->time_to_die)
			{
				died(philo);
				return ;
			}
		}
		i++;
	}
}

static void	monitor(t_data *data)
{
	int	running;
	int	finished_count;

	while (1)
	{
		pthread_mutex_lock(&data->running_mutex);
		running = data->is_running;
		pthread_mutex_unlock(&data->running_mutex);
		if (!running)
			return ;
		finished_count = 0;
		check_philos(data, &finished_count);
		if (finished_count == data->philo_count)
		{
			pthread_mutex_lock(&data->running_mutex);
			data->is_running = 0;
			pthread_mutex_unlock(&data->running_mutex);
			return ;
		}
		allow_philos_to_eat(data);
		usleep(500);
	}
}

int	simulation(t_data *data)
{
	int		i;
	t_philo	*philo;

	data->start_time = get_time_in_ms();
	data->is_running = 1;
	i = 0;
	while (i < data->philo_count)
	{
		philo = &data->philos[i];
		philo->last_meal_time = get_time_in_ms();
		if (philo->id % 2 == 0)
			philo->allowed = 1;
		if (pthread_create(&philo->thread, NULL, routine, philo))
		{
			pthread_mutex_lock(&data->running_mutex);
			data->is_running = 0;
			pthread_mutex_unlock(&data->running_mutex);
			return (my_error("error creating philo thread"));
		}
		i++;
	}
	monitor(data);
	return (0);
}
