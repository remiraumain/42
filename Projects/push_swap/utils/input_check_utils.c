/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:01:53 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/28 16:02:57 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	get_sign(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	return (0);
}

int	cmp_word(const char *s1, const char *s2, int s2_len)
{
	int	j;
	int	count;
	int	word_len;

	if (!s1 || !s2 || !s2_len)
		return (0);
	count = 0;
	while (*s1)
	{
		word_len = 0;
		while (is_digit(s1[word_len]) || get_sign(s1[word_len]))
			word_len++;
		j = 0;
		while ((unsigned char)s1[j] == (unsigned char)s2[j] && j < s2_len)
			j++;
		if (j == s2_len && word_len == s2_len)
		{
			count++;
			if (count == 2)
				return (1);
		}
		s1 += word_len + 1;
	}
	return (0);
}