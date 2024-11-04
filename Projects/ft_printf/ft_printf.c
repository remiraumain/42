/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:04:04 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/04 17:47:47 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			len += process_selector(*format, args);
		}
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	ft_printf("Hello %s\n", "world");
	ft_printf("Hello %c\n", 'u');
	ft_printf("Hello %d\n", 42);
	ft_printf("Hello %%\n");
	return (0);
}
