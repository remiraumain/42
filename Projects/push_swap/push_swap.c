/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:21:59 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/28 13:36:36 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	push_swap(t_stack **a, t_stack **b, int stack_size)
// {
// 	if (is_sorted(*a)) // is_sorted check if stack_size == 1 and return true
// 		return ;
// 	if (stack_size == 2)
// 		return (do_sa(a)); // Todo
// 	else if (stack_size == 3)
// 		hard_sort(a); // Todo hard coded sort
// 	else if (stack_size == 4 || stack_size == 5)
// 		hard_sort_op(a); // Todo
// 	else if (stack_size >= 6 && stack_size < 100)
// 		insert_sort(a); // Todo
// 	else
// 		radix_sort(a, b); // Todo
// 	free_stack(b);
// }

int	main(int argc, char **argv)
{
	argv[1] = "5 1 2 3 4";
	argc = 2;
	// t_stack	*a;
	// t_stack	*b;

	// a = NULL;
	// b = NULL;
	if (argc != 2)
		return (1);
	if (!is_input_correct(argv[1]))
		return (1); // return error\n
	
	// fill_stack(a);
	// push_swap(a, b, get_size(a));
	// free_stack(a);
	return (0);
}
