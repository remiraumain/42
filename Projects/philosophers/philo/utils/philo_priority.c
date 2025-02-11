/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_priority.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:54:28 by rraumain          #+#    #+#             */
/*   Updated: 2025/02/11 15:28:40 by rraumain         ###   ########.fr       */
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

static t_philo	*pick_most_hungry_in_round(t_data *data)
{
	t_philo	*most_hungry;
	t_philo	*philo;
	int		i;

	most_hungry = NULL;
	i = 0;
	while (i < data->philo_count)
	{
		philo = &data->philos[i];
		pthread_mutex_lock(&philo->data_mutex);
		if (is_in_current_round(philo, data->current_round)
			&& !philo->finished
			&& !philo->allowed
			&& !philo->ate_this_round
			&& !is_next_to_allowed(philo))
		{
			if (!most_hungry)
				most_hungry = philo;
			else if (philo->last_meal_time < most_hungry->last_meal_time)
				most_hungry = philo;
		}
		pthread_mutex_unlock(&philo->data_mutex);
		i++;
	}
	return (most_hungry);
}

static int	all_in_round_ate(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < data->philo_count)
	{
		philo = &data->philos[i];
		pthread_mutex_lock(&philo->data_mutex);
		if (is_in_current_round(philo, data->current_round)
			&& philo->ate_this_round == 0)
		{
			pthread_mutex_unlock(&philo->data_mutex);
			return (0);
		}
		pthread_mutex_unlock(&philo->data_mutex);
		i++;
	}
	return (1);
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
