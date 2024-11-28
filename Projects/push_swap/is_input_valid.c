/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_input_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:49:34 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/28 16:35:20 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	type_check(const char *input)
{
	unsigned long	i;

	i = 0;
	while (input[i])
	{
		if (input[0] == ' ')
			return (0);
		if (get_sign(input[0]) && !is_digit(input[1]))
			return (0);
		if (input[i] != ' ' 
			&& !get_sign(input[i]) && !is_digit(input[i]))
			return (0);
		if (input[i] == ' ' 
			&& !(is_digit(input[i + 1]) || get_sign(input[i + 1])))
			return (0);
		if (i && get_sign(input[i]) 
			&& !(is_digit(input[i + 1]) && input[i - 1] == ' '))
			return (0);
		i++;
	}
	return (1);
}

static int	is_at_least_2(const char *input)
{
	int				i;
	unsigned long	len;

	i = 0;
	while (*input)
	{
		len = 0;
		while (is_digit(*input) || get_sign(*input))
		{
			len++;
			input++;
		}
		if (len)
			i++;
		input++;
	}
	if (i >= 2)
		return (1);
	return (0);
}

static int	in_range(const char *input)
{
	int				sign;
	unsigned long	i;

	while (*input)
	{
		sign = 0;
		i = 1;
		if (*input == ' ')
			input++;
		sign = get_sign(*input);
		if (sign)
			input++;
		while (is_digit(input[i]))
			i++;
		if (i > 11)
			return (0);
		if (i == 11 
		&& ((sign == 1 
		&& (input[0] > '2' || (input[0] == '2' && input[9] > 7))) 
		|| (sign == -1 
		&& (input[0] > '2' || (input[0] == '2' && input[9] > 8)))))
				return (0);
		input += i;
	}
	return (1);
}

static int	has_dup(const char *input)
{
	unsigned long	end;
	unsigned long	start;

	end = 0;
	while (input[end])
	{
		start = end;
		while (is_digit(input[end]) || get_sign(input[end]))
			end++;
		if (cmp_word(input, &input[start], end - start))
			return (1);
		end++;
	}
	return (0);
}

int	is_input_valid(const char *input)
{
	if (!input || !input[0])
		return (0);
	if (!type_check(input))
		return (0);
	if (!is_at_least_2(input))
		return (0);
	if (!in_range(input))
		return (0);
	if (has_dup(input))
		return (0);
	return (1);
}
