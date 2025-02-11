/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:29:51 by rraumain          #+#    #+#             */
/*   Updated: 2025/02/11 15:28:20 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	take_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
	}
	print_action(philo, "has taken a fork");
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	eat(t_philo *philo)
{
	print_action(philo, "is eating");
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_lock(&philo->data_mutex);
	philo->allowed = 0;
	philo->ate_this_round = 1;
	philo->meals_eaten++;
	philo->last_meal_time = get_time_in_ms();
	if (philo->meals_eaten >= philo->data->nb_of_meals)
		philo->finished = 1;
	pthread_mutex_unlock(&philo->data_mutex);
}

void	sleep_and_think(t_philo *philo)
{
	print_action(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
	print_action(philo, "is thinking");
}
