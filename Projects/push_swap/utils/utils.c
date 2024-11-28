/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:01:53 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/28 13:30:03 by rraumain         ###   ########.fr       */
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

int	cmp_word(const char *s1, const char *s2, int start, int end)
{
	int	i;
	int	j;

	if (!start || !end)
		return (0);
	i = 0;
	while (s1[i])
	{
		if (i >= start)
			i = end;
		j = 0;
		while (j < end && ((unsigned char)s1[i] == (unsigned char)s2[j]))
			j++;
		if (j == end)
			return (1);
		i++;
		}
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
