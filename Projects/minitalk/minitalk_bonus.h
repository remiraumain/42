/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 22:03:27 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/22 16:36:37 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_sigbyte
{
	unsigned char	byte;
	int				count;
	char			*string;
}	t_sigbyte;

int			g_res = 0;
t_sigbyte	g_sigbyte = {0};

#endif