/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:48:54 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/15 12:06:55 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*error(char *message)
{
	ft_printf("Error\n");
	ft_printf("%s\n", message);
	return (NULL);
}

int	error_int(char *message)
{
	ft_printf("Error\n");
	ft_printf("%s\n", message);
	return (-1);
}
