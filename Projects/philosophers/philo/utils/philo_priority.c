/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_priority.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:54:28 by rraumain          #+#    #+#             */
/*   Updated: 2025/02/11 16:44:54 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_next_to_allowed(t_philo *philo)
{
	t_philo	*left_philo;
	t_philo	*right_philo;
	int		left_allowed;
	int		right_allowed;

	if (philo->data->philo_count <= 1)
		return (1);
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

static int	is_eligible_to_most_hungry(t_data *data, t_philo *philo,
long *meal_time)
{
	int	id;
	int	finished;
	int	allowed;
	int	ate;

	finished = 0;
	allowed = 0;
	ate = 0;
	pthread_mutex_lock(&philo->data_mutex);
	id = philo->id;
	finished = philo->finished;
	allowed = philo->allowed;
	ate = philo->ate_this_round;
	*meal_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->data_mutex);
	if (is_in_current_round(id, finished, data->current_round)
		&& !finished
		&& !allowed
		&& !ate
		&& !is_next_to_allowed(philo))
		return (1);
	return (0);
}

static t_philo	*pick_most_hungry_in_round(t_data *data)
{
	t_philo	*most_hungry;
	int		i;
	long	most_hungry_lmt;
	long	philo_lmt;

	most_hungry = NULL;
	i = 0;
	while (i < data->philo_count)
	{
		if (is_eligible_to_most_hungry(data, &data->philos[i], &philo_lmt))
		{
			if (!most_hungry)
				most_hungry = &data->philos[i];
			else
			{
				pthread_mutex_lock(&most_hungry->data_mutex);
				most_hungry_lmt = most_hungry->last_meal_time;
				pthread_mutex_unlock(&most_hungry->data_mutex);
				if (philo_lmt < most_hungry_lmt)
					most_hungry = &data->philos[i];
			}
		}
		i++;
	}
	return (most_hungry);
}

static void	authorize_one_in_round(t_data *data)
{
	t_philo	*philo;

	philo = pick_most_hungry_in_round(data);
	if (!philo)
		return ;
	pthread_mutex_lock(&philo->data_mutex);
	philo->allowed = 1;
	pthread_mutex_unlock(&philo->data_mutex);
}

void	round_update(t_data *data)
{
	if (all_in_round_ate(data))
	{
		data->current_round = !data->current_round;
		reset_ate_flags(data);
		return ;
	}
	authorize_one_in_round(data);
}
