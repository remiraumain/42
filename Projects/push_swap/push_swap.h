/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:22:09 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/20 20:02:22 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct	s_stack
{
	int					nbr;
	// isnegative
	// saved_byte
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

int	is_input_valid(const char **input);

#endif
