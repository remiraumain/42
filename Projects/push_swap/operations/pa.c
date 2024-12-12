/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:16:34 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/12 12:11:53 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **b, t_stack **a)
{
	t_stack	*new_first;

	new_first = *b;
	if ((*b)->next)
		*b = (*b)->next;
	else
		*b = NULL;
	new_first->next = *a;
	*a = new_first;
	write(1, "pa\n", 3);
}
