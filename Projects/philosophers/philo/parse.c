/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:50:13 by rraumain          #+#    #+#             */
/*   Updated: 2025/02/13 12:03:56 by rraumain         ###   ########.fr       */
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

static int	set_args(char **av, t_data *data)
{
	int	arg;
	int	i;

	i = 1;
	while (av[i])
	{
		arg = my_atoi(av[i]);
		if (arg < 0)
		{
			my_error("args must be positive numbers (0 to max int)");
			return (1);
		}
		add_args_to_data(arg, i, data);
		i++;
	}
	return (0);
}

int	parse(int ac, char **av, t_data *data)
{
	if (ac < 5 || ac > 6)
	{
		my_error("invalid args: ./philo nb_philos time_to_die time_to_eat \
		time_to_sleep [nb_meals]");
		return (1);
	}
	if (set_args(av, data))
		return (1);
	if (ac == 5)
		data->nb_of_meals = 1;
	if (data->philo_count < 1)
	{
		my_error("must have at least one philosopher");
		return (1);
	}
	return (0);
}
