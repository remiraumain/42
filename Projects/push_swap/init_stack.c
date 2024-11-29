/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:10:47 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/29 18:57:58 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_stack_head(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

static void	create_stack_node(const char *input, t_stack **a)
{
	int nb;
	int	sign;
	t_stack	*prev;

	nb = 0;
	prev = *a;
	sign = get_sign(*input);
		if (sign != -1)
			sign = 1;
	while(is_digit(*input) || get_sign(*input))
	{
		nb = nb * 10 + *input - '0';
		input++;
	}
	*a = malloc(sizeof(t_stack));
	if (!*a)
		return ;
	if (prev)
		prev->next = *a;
	(*a)->next = NULL;
	(*a)->prev = prev;
	(*a)->actions_nb = 0;
	(*a)->value = nb *sign;
}

int	init_stack(t_stack **a, const char *input)
{
	t_stack	*last;

	while(*input)
	{
		last = *a;
		create_stack_node(input, a);
		if (!*a)
		{
			free_stack(last);
			return (0);
		}
		while (is_digit(*input) || get_sign(*input))
			input++;
		if (*input == ' ')
			input++;
	}
	last = *a;
	*a = get_stack_head(*a);
	last->next = *a;
	(*a)->prev = last;
	return (1);
}
