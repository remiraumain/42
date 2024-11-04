/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:04:04 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/04 13:57:59 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	len;
	va_list	args;

	va_start(args, format);

	len = 0;
	while (*format)
	{
		if (format == '%' && (format + 1))
		{
			format++;
			// manage different sleector
		}
		else 
			// putchar the character and increment len
		format++;
	}
	va_end(args);
	return (len);
}
