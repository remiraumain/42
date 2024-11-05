/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:58:35 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/05 07:13:12 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_selector(char selector, va_list *args)
{
	if (selector == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (selector == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (selector == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (selector == 'd')
		return (ft_putnbr(va_arg(*args, int)));
	else if (selector == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (selector == 'u')
		return (ft_putnbr(va_arg(*args, unsigned int)));
	else if (selector == 'x')
		return (ft_puthex(va_arg(*args, int), 0));
	else if (selector == 'X')
		return (ft_puthex(va_arg(*args, int), 1));
	else if (selector == '%')
		return (ft_putchar('%'));
	return (-1);
}
