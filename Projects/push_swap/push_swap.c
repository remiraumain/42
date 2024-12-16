/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:21:59 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/16 10:38:50 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if (!parse(argc, argv, &a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	sort(&a);
	stack_clear(&a);
	return (0);
}
