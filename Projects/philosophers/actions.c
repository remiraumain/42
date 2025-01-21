/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:29:51 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/21 14:49:37 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_action(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%ld %d %s\n", get_time_in_ms() - philo->data->start_time, philo->id, action);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken a fork");
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}

void	eat(t_philo *philo)
{
	if (!(philo->left_fork && philo->right_fork))
		return ;
	print_action(philo, "is eating");
	usleep(philo->data->time_to_eat);
	philo->meals_eaten++;
	philo->last_meal_time = get_time_in_ms();
}

void	sleep_and_think(t_philo *philo)
{
	usleep(philo->data->time_to_sleep);
	print_action(philo, "is sleeping");
	print_action(philo, "is thinking");
}

