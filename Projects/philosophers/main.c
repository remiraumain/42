/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:47:36 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/20 22:08:58 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

int	main(int ac, char **av)
{
	t_data	data;

	if (parse(ac, av, &data))
		return (1);
	if (init(&data))
		return (my_error("an error occured during initialisating data"));
	clear(&data);
	return (0);
}
