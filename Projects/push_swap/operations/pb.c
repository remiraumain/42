/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:16:42 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/12 12:11:05 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*new_first;

	new_first = *a;
	*a = (*a)->next;
	new_first->next = *b;
	*b = new_first;
	write(1, "pb\n", 3);
}
