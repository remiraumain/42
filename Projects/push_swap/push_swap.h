/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:22:09 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/16 10:36:28 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "struct.h"
# include "libft/libft.h"
# include "operations/operations.h"
# include "utils/utils.h"

int		parse(int argc, char **argv, t_stack **a);
void	sort(t_stack **a);

#endif
