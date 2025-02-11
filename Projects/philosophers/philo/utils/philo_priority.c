/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_priority.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:54:28 by rraumain          #+#    #+#             */
/*   Updated: 2025/02/11 12:15:37 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_neighbors(t_philo *philo, t_philo **left, t_philo **right)
{
	t_data	*data;
	int		id;

	data = philo->data;
	id = philo->id;
	if (id == 1)
	{
		*left = &data->philos[data->philo_count - 1];
		*right = &data->philos[1];
	}
	else if (id == data->philo_count)
	{
		*left = &data->philos[id - 2];
		*right = &data->philos[0];
	}
	else
	{
		*left = &data->philos[id - 2];
		*right = &data->philos[id];
	}
}

static int	is_next_to_allowed(t_philo *philo)
{
	t_philo	*left_philo;
	t_philo	*right_philo;
	int		left_allowed;
	int		right_allowed;

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

static int	allow_count(t_data *data, int *to_allow)
{
	int		i;
	int		j;
	t_philo	*philo;

	i = 0;
	j = 0;
	while (i < data->philo_count)
	{
		philo = &data->philos[i];
		pthread_mutex_lock(&philo->data_mutex);
		if (!philo->finished && !philo->allowed && !is_next_to_allowed(philo))
		{
			to_allow[j] = philo->id;
			j++;
		}
		pthread_mutex_unlock(&philo->data_mutex);
		i++;
	}
	to_allow[j] = 0;
	return (j);
}

static t_philo	*pick_most_hungry(t_data *data, int *to_allow)
{
	t_philo	*current;
	t_philo	*most_hungry;
	int		i;
	int		index;

	most_hungry = NULL;
	i = 0;
	while (to_allow[i] != 0)
	{
		index = to_allow[i] - 1;
		current = &data->philos[index];
		pthread_mutex_lock(&current->data_mutex);
		if (!current->finished && !current->allowed
			&& !is_next_to_allowed(current))
		{
			if (!most_hungry
				|| current->last_meal_time < most_hungry->last_meal_time)
				most_hungry = current;
		}
		pthread_mutex_unlock(&current->data_mutex);
		i++;
	}
	return (most_hungry);
}

void	allow_philos_to_eat(t_data *data)
{
	int		*to_allow;
	int		count;
	t_philo	*most_hungry;

	if (data->philo_count == 1)
		return ;
	to_allow = malloc(sizeof(int) * (data->philo_count + 1));
	if (!to_allow)
		return ;
	count = allow_count(data, to_allow);
	while (count > 0)
	{
		most_hungry = pick_most_hungry(data, to_allow);
		if (most_hungry)
		{
			pthread_mutex_lock(&most_hungry->data_mutex);
			most_hungry->allowed = 1;
			pthread_mutex_unlock(&most_hungry->data_mutex);
			remove_id_from_array(to_allow, most_hungry->id);
		}
		count--;
	}
	free(to_allow);
}
