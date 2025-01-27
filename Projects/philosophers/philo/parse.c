/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:50:13 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/27 10:07:31 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	add_args_to_data(int arg, int index, t_data *data)
{
	if (index == 1)
		data->philo_count = arg;
	else if (index == 2)
		data->time_to_die = arg;
	else if (index == 3)
		data->time_to_eat = arg;
	else if (index == 4)
		data->time_to_sleep = arg;
	else
		data->nb_of_meals = arg;
}

int	parse(int ac, char **av, t_data *data)
{
	int	i;
	int	arg;

	if (ac < 5 || ac > 6)
		return (my_error("invalid args: ./philo nb_philos time_to_die time_to_eat \
time_to_sleep [nb_meals]"));
	i = 1;
	while (av[i])
	{
		arg = my_atoi(av[i]);
		if (arg < 0)
			return (my_error("args must be positive numbers (0 to max int)"));
		add_args_to_data(arg, i, data);
		i++;
	}
	if (data->philo_count < 1)
		return (my_error("must have at least one philosopher"));
	return (0);
}
