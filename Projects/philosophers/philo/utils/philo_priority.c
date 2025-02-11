/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_priority.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:54:28 by rraumain          #+#    #+#             */
/*   Updated: 2025/02/11 12:58:55 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	allow_count(t_data *data, int *to_allow)
{
	int		i;
	int		j;
	t_philo	*philo;
	int		finished;
	int		allowed;

	i = 0;
	j = 0;
	while (i < data->philo_count)
	{
		philo = &data->philos[i];
		pthread_mutex_lock(&philo->data_mutex);
		finished = philo->finished;
		allowed = philo->allowed;
		pthread_mutex_unlock(&philo->data_mutex);
		if (!finished && !allowed && !is_next_to_allowed(philo))
		{
			to_allow[j] = philo->id;
			j++;
		}
		i++;
	}
	to_allow[j] = 0;
	return (j);
}

static t_philo	*check_candidate(t_data *data, t_philo *most_hungry, int id)
{
	t_philo	*candidate;
	int		finished;
	int		allowed;
	int		candidate_lmt;
	int		most_hungry_lmt;

	candidate = &data->philos[id - 1];
	pthread_mutex_lock(&candidate->data_mutex);
	finished = candidate->finished;
	allowed = candidate->allowed;
	candidate_lmt = candidate->last_meal_time;
	pthread_mutex_unlock(&candidate->data_mutex);
	if (finished || allowed || is_next_to_allowed(candidate))
		return (most_hungry);
	if (!most_hungry)
		return (candidate);
	pthread_mutex_lock(&most_hungry->data_mutex);
	most_hungry_lmt = most_hungry->last_meal_time;
	pthread_mutex_unlock(&most_hungry->data_mutex);
	if (candidate_lmt < most_hungry_lmt)
		return (candidate);
	return (most_hungry);
}

static t_philo	*pick_most_hungry(t_data *data, int *to_allow)
{
	t_philo	*most_hungry;
	int		i;
	int		id;

	most_hungry = NULL;
	i = 0;
	while (to_allow[i] != 0)
	{
		id = to_allow[i];
		most_hungry = check_candidate(data, most_hungry, id);
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
