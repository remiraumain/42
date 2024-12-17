/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 22:03:27 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/17 20:04:58 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct sigbyte_s {
	unsigned char	byte;
	int				count;
}	sigbyte_t;

int			res = 0;
sigbyte_t	sigbyte = {0};

#endif