/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:59:26 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/15 21:09:44 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*second;

	second = (*a)->next;
	(*a)->next = second->next;
	second->next = *a;
	*a = second;
	write(1, "sa\n", 3);
}
