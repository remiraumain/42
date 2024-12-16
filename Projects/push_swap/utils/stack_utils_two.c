/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_extended.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:54:52 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/16 09:58:49 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

unsigned int	stack_size(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack	*get_second_last(t_stack *stack)
{
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

void	bring_to_top(t_stack **a, unsigned int pos)
{
    unsigned int size;
    unsigned int half;

    size = stack_size(*a);
    half = size / 2;
    if (pos <= half)
    {
        while (pos > 0)
        {
            ra(a);
            pos--;
        }
    }
    else
    {
        while (pos < size)
        {
            rra(a);
            pos++;
        }
    }
}

unsigned int get_min_pos(t_stack *a)
{
    unsigned int	pos;
	unsigned int	max;

    pos = 0;
	max = stack_size(a);
    while (a)
    {
        if (a->index == max)
        	return (pos);
        a = a->next;
        pos++;
    }
    return (pos);
}
