/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:57:39 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/20 22:01:28 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	clear(t_data *data)
{
	int	i;

	i = 0;
	if (!data)
        return (1);
	if (data->forks)
	{
		while (i < data->philo_count && data->mutex_init)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
	}
	if (data->mutex_init)
	{
		pthread_mutex_destroy(&data->print_mutex);
		pthread_mutex_destroy(&data->death_mutex);
	}
	if (data->philos)
		free(data->philos);
	my_memset(data, 0, sizeof(t_data));
	return (1);
}
