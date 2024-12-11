/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:22:09 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/11 10:20:58 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				actions_nb;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

int		parse(int argc, char **argv, t_stack **a);
int		has_dup(t_stack **a);
// utils
t_stack	*stack_new(int value);
void	stack_clear(t_stack **stack);
void	stack_delone(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_last(t_stack *stack);
int		stack_size(t_stack *stack);

#endif
