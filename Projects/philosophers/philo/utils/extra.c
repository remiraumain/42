/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:21:13 by rraumain          #+#    #+#             */
/*   Updated: 2025/02/11 12:15:53 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	died(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->running_mutex);
	data->is_running = 0;
	pthread_mutex_unlock(&data->running_mutex);
	pthread_mutex_lock(&data->print_mutex);
	printf("%ld %d died\n", get_time_in_ms() - data->start_time, philo->id);
	pthread_mutex_unlock(&data->print_mutex);
}

void	remove_id_from_array(int *array, int id)
{
	int	i;

	i = 0;
	while (array[i] != 0)
	{
		if (array[i] == id)
		{
			while (array[i] != 0)
			{
				array[i] = array[i + 1];
				i++;
			}
			return ;
		}
		i++;
	}
}
