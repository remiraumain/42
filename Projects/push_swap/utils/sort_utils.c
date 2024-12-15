/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 07:55:39 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/15 20:46:44 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*prev;

	prev = stack;
	while (stack)
	{
		if (stack->value < prev->value)
			return (0);
		prev = stack;
		stack = stack->next;
	}
	return (1);
}

void	radix(t_stack **a)
{
	t_stack			*b;
	unsigned int	size;
	unsigned int	i;
	unsigned int	j;

	b = NULL;
	i = 0;
	size = stack_size(*a);
	while (!is_sorted(*a))
	{
		j = 0;
		while (j < size)
		{
			if ((*a)->index & (1 << i))
				pb(a, &b);
			else
				ra(a);
			j++;
		}
		while (b)
			pa(&b, a);
		i++;
	}
}
