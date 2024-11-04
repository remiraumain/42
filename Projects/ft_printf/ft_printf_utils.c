/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:58:35 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/04 17:47:22 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_selector(char selector, va_list args)
{
	if (selector == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (selector == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (selector == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (selector == '%')
		return (ft_putchar('%'));
	return (-1);
}
