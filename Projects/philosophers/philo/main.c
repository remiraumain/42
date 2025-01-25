/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:47:36 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/25 11:11:44 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
// ./a.out 300 150 99 1 2 | grep -E " (2 is eating|died)
int	main(int ac, char **av)
{
	t_data	data;

	if (parse(ac, av, &data))
		return (2);
	if (init(&data))
		return (my_error("an error occured during initialisating data"));
	if (start_simu(&data))
		return (2);
	clear(&data);
	return (0);
}
