/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:54:59 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/12 11:58:41 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

# include "../push_swap.h"

int		has_dup(t_stack **a);
void	set_index(t_stack *stack, int size);
t_stack	*stack_new(int value);
void	stack_clear(t_stack **stack);
void	stack_delone(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_last(t_stack *stack);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
int		is_sorted_dec(t_stack *stack);
void	radix(t_stack **a);

#endif