/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:57:39 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/21 01:12:18 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	clear_philo(t_data *data)
{
	int i = 0;
	while (i < data->philo_count)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	free(data->philos);
}

void	clear_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
}

int	clear(t_data *data)
{
	int	i;

	i = 0;
	if (!data)
        return (1);
	if (data->philos)
		clear_philo(data);
	if (data->mutex_init)
		clear_mutex(data);
	my_memset(data, 0, sizeof(t_data));
	return (1);
}
