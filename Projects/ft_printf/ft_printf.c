/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:23:23 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/05 18:11:38 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Print ARGUMENT(s) according to FORMAT.
 *
 * @param format The format string.
 * @param args The content to output (variadic variable).
 * @return The lenght of the output.
 * @note List of selectors: `%c` `%s` `%p` `%d` `%i` `%u` `%x` `%X` `%%`
 */
int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	if (!format)
		return (-1);
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
