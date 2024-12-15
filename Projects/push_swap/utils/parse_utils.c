/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:19:45 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/15 20:49:00 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	has_dup(t_stack **a)
{
	t_stack	*current;
	t_stack	*next;

	current = *a;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (current->value == next->value)
				return (1);
			next = next->next;
		}
		current = current->next;
	}
	return (0);
}

void	set_index(t_stack *stack, unsigned int size)
{
	t_stack	*current;
	t_stack	*min_node;
	int		min_value;

	while (size)
	{
		min_node = NULL;
		min_value = 2147483647;
		current = stack;
		while (current)
		{
			if (!current->index && current->value <= min_value)
			{
				min_value = current->value;
				min_node = current;
			}
			current = current->next;
		}
		if (min_node)
			min_node->index = size;
		size--;
	}
}
