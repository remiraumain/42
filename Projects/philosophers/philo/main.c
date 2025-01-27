/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:47:36 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/27 10:21:11 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
