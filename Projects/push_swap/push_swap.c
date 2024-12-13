/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:21:59 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/13 14:11:53 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// static void	push_swap(t_stack **a, t_stack **b, int stack_size)
// {
// 	if (is_sorted(*a)) // is_sorted check if stack_size == 1 and return true
// 		return ;
// 	if (stack_size == 2)
// 		return (do_sa(a)); // Todo
// 	else if (stack_size == 3)
// 		return sort_three(a); // Todo hard coded sort
// 	else if (stack_size == 4 || stack_size == 5)
// 		sort_five(a); // Todo
// 	else 
// 		sort_big(a); // Todo
// 	free_stack(b);
// }

int	main(int argc, char **argv)
{
	// argc = 2;
	// argv[1] = "2 1 3";
	t_stack	*a;

	a = NULL;
	if (!parse(argc, argv, &a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	sort(&a);
	stack_clear(&a);
	return (0);
}

