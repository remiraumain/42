/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:08:43 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/12 11:59:26 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*last;
	t_stack	*new_first;

	new_first = (*a)->next;
	last = stack_last(*a);
	(*a)->next = NULL;
	last->next = *a;
	*a = new_first;
	write(1, "ra\n", 3);
}
