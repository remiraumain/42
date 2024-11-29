/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:22:09 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/29 13:27:40 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				actions_nb;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

int	is_digit(char c);
int	get_sign(char c);
int	cmp_word(const char *s1, const char *s2, unsigned long s2_len);
int	is_input_valid(const char *input);
int	init_stack(t_stack **a, const char *input);


#endif
