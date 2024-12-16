/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:54:59 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/16 09:56:07 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../push_swap.h"

int				has_dup(t_stack **a);
void			set_index(t_stack *stack, unsigned int size);
t_stack			*stack_new(int value);
void			stack_clear(t_stack **stack);
void			stack_delone(t_stack *stack);
void			stack_add_back(t_stack **stack, t_stack *new);
t_stack			*stack_last(t_stack *stack);
unsigned int	stack_size(t_stack *stack);
t_stack			*get_second_last(t_stack *stack);
void			bring_to_top(t_stack **a, unsigned int pos);
unsigned int 	get_min_pos(t_stack *a);
int				is_sorted(t_stack *stack);
void			sort_three(t_stack **a);
void			sort_five(t_stack **a);
void			radix(t_stack **a);

#endif