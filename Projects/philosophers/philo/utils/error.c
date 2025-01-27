/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:55:53 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/27 10:19:35 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	my_error(char *message)
{
	unsigned int	len;

	len = my_strlen(message);
	write(1, "Error: ", 7);
	write(1, message, len);
	write(1, "\n", 1);
	return (2);
}
