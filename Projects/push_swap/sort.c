/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:12:46 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/15 21:14:48 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a)
{
	int	stack_len;

	if (is_sorted(*a))
		return ;
	stack_len = stack_size(*a);
	if (stack_len == 2)
		ra(a);
	else if (stack_len == 3)
		sort_three(a);
	// else if (stack_len < 6)
	// 	sort5(a);
	else
		radix(a);
}
