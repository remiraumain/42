/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:58:35 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/04 16:20:30 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_selector(char *format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg)));
	else if (format == 's')
		return (ft_putstr(format));
}