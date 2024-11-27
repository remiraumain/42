/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_input_correct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:49:34 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/27 11:15:54 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** 
 * This should work
 * 
 * ./push_swap "1 2 4 3"
 * ./push_swap "-2147483648 2147483647"
 * 
 * This should not (return "error\n")
 * 
 * ./push_swap "1 2 1"
 * ./push_swap 1 2 1
 * ./push_swap " 1 2"
 * ./push_swap 2147483 	6481902020983
 * ./push_swap
 * ./push_swap " "
 * ./push_swap 2147483647 10 0
 * ./push_swap "1 2 4 3" 76 90 "348 05 (half string half number)
 * 
 * Check 
 * 
 * ./push_swap " 1"
 * ./push_swap "1  2"
 */

#include "push_swap.h"

static int	type_check(const char *input)
{
	unsigned long	i;

	i = 0;
	while (input[i])
	{
		if (input[0] == ' ')
			return (0);
		if (get_sign(input[0]) && !is_digit(input[i + 1]))
			return (0);
		if (input[i] != ' ' && !get_sign(input[i]) && !is_digit(input[i]))
			return (0);
		if (input[i] == ' ' && !(is_digit(input[i + 1]) || get_sign(input[i + 1])))
			return (0);
		if (get_sign(input[i]) && !(is_digit(input[i + 1]) && input[i - 1] == ' '))
			return (0);
		i++;
	}
	return (1);
}

static int	in_range(const char *input)
{
	int	sign;
	int	i;

	while (*input)
	{
		sign = 0;
		i = 1;
		if (*input == ' ')
			input++;
		sign = get_sign(*input);
		if (sign)
			input++;
		while (is_digit(input[i]))
			i++;
		if (i > 11)
			return (0);
		if (i == 11 
		&& ((sign == 1 
		&& (input[0] > '2' || (input[0] == '2' && input[9] > 7))) 
		|| (sign == -1 
		&& (input[0] > '2' || (input[0] == '2' && input[9] > 8)))))
				return (0);
		input += i;
	}
	return (1);
}

static int	has_dup(const char *input)
{
	int	i;
	int j;
	int	start;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i] == ' ')
			i++;
		start = i;
		while (is_digit(input[i] || get_sign(input[i])))
			i++;
		while(input[j] && input[j + i])
		{
			if (j == start)
				j = i;
			
		}
		
	}
}

// static int	normalize(t_stack *stack)
// {

// }

// static int	fill_stack(const char *input, t_stack **stack)
// {
// 	t_stack	*last;

// 	last = NULL;
//     while (*input)
//     {
// 		while (*input == ' ')
// 			input++;
// 		stack = malloc(sizeof(t_stack **));
// 		if (!stack)
// 			return 0;
//         if (!extract_number(input, stack))
//         {
//             free(stack);
//             return (0);
//         }
// 		else 
// 		{
// 			(*stack)->prev = last;
// 			(*stack)->next = NULL;
// 			last = *stack;
// 		}
// 		while (*input != ' ' && *input)
// 			input++;
//     }
//     return (1);
// }

int	is_input_correct(const char *input, t_stack **a)
{
	if (!input || !input[0])
		return (0);
	if (!type_check(input))
		return (0);
	if (!in_range(input))
		return (0);
	// if (!fill_stack(input, a))
	// 	return (0);
	if (has_dup(input))
		return (0);
	
	return (1);
}
