/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:19:45 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/16 10:40:38 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_arg_valid(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9')
			&& !((arg[i] == '-' || arg[i] == '+') && i == 0))
			return (0);
		i++;
	}
	if (!check_size(arg))
		return (0);
	return (1);
}

int	check_size(char *s)
{
	int	len;
	int	sign;

	sign = 0;
	len = ft_strlen(s);
	if (s[0] == '-' || s[0] == '+')
	{
		len--;
		sign++;
	}
	if (len > 10 || len < 1)
		return (0);
	if (len < 10)
		return (1);
	if (s[0 + sign] > '2'
		|| (s[0 + sign] == '2' && s[len + sign - 1] > '7' && s[0] != '-'))
		return (0);
	if (s[0 + sign] > '2'
		|| (s[0 + sign] == '2' && s[len + sign - 1] > '8' && s[0] == '-'))
		return (0);
	return (1);
}

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
