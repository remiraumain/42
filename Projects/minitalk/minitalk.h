/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 22:03:27 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/25 07:34:55 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_sigbyte
{
	unsigned char	byte;
	int				count;
	char			*string;
}	t_sigbyte;

int			g_res = 0;
t_sigbyte	g_sigbyte = {0};

#endif