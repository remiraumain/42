/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:55:53 by rraumain          #+#    #+#             */
/*   Updated: 2025/02/13 11:47:32 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_error(char *message)
{
	unsigned int	len;

	len = my_strlen(message);
	write(2, "Error: ", 7);
	write(2, message, len);
	write(2, "\n", 1);
}
