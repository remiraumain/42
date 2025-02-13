/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:21:13 by rraumain          #+#    #+#             */
/*   Updated: 2025/02/13 12:10:31 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_neighbors(t_philo *philo, t_philo **left, t_philo **right)
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

int	is_in_current_round(int id, int finished, int current_round)
{
	if (finished)
		return (0);
	if (current_round == 0 && (id % 2) == 0)
		return (1);
	if (current_round == 1 && (id % 2) == 1)
		return (1);
	return (0);
}

int	all_in_round_ate(t_data *data)
{
	int		i;
	t_philo	*philo;
	int		id;
	int		finished;

	i = 0;
	while (i < data->philo_count)
	{
		philo = &data->philos[i];
		pthread_mutex_lock(&philo->data_mutex);
		id = philo->id;
		finished = philo->finished;
		pthread_mutex_unlock(&philo->data_mutex);
		if (is_in_current_round(id, finished, data->current_round)
			&& philo->ate_this_round == 0)
			return (0);
		i++;
	}
	return (1);
}

void	reset_ate_flags(t_data *data)
{
	int		i;
	t_philo	*philo;
	int		id;
	int		finished;

	i = 0;
	while (i < data->philo_count)
	{
		philo = &data->philos[i];
		pthread_mutex_lock(&philo->data_mutex);
		id = philo->id;
		finished = philo->finished;
		pthread_mutex_unlock(&philo->data_mutex);
		if (is_in_current_round(id, finished, data->current_round))
			philo->ate_this_round = 0;
		i++;
	}
}
