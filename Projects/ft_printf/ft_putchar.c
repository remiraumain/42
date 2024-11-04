/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:00:46 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/04 22:07:41 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/**
 * @brief Output the character `c`.
 *
 * @param c The character to output.
 * @return The lenght so `1`.
 */
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
