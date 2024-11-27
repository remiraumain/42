/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:01:53 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/27 11:15:56 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	get_sign(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	return (0);
}

// int extract_number(const char *str, t_stack **stack)
// {
//     int sign;

//     (*stack)->value = 0;
//     while (*str == ' ')
//         str++;
//     sign = get_sign(*str);
//     if (sign != 0)
//         str++;
// 	else
// 		sign = 1;
//     while (is_digit(*str))
//     {
//         (*stack)->value = (*stack)->value * 10 + (*str - '0');
//         str++;
//     }
//     (*stack)->value = (*stack)->value * sign;
//     if (sign != 0 || (*stack)->value != 0)
//         return 1;
//     return 0;
// }
