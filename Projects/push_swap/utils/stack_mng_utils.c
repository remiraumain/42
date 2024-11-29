/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mng_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:09:49 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/29 18:55:50 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*next;

	next = NULL;
	while (stack)
	{
		next = stack->next;
		stack->value = 0;
		stack->actions_nb = 0;
		stack->prev = NULL;
		stack->next = NULL;
		stack = NULL;
		free(stack);
		stack = next;
	}
}
