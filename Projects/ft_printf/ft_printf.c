/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:23:23 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/05 07:26:16 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			len += ft_selector(*format, &args);
		}
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	ft_printf("ft_printf: %d \n", -10);
// 	printf("printf: %d ", -10);
// 	return (0);
// }
