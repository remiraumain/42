/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:19:45 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/11 10:27:57 by rraumain         ###   ########.fr       */
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