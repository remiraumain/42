/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:02:24 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/15 21:09:46 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*second_last;

	last = stack_last(*a);
	second_last = get_second_last(*a);
	second_last->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}
