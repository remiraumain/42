/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 07:51:56 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 12:21:05 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <ctype.h>

// Test uppercase characters.
void	test_ft_isalpha_upper(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = 'H';
	expected = isalpha(c);
	actual = ft_isalpha(c);
	assert_eq(expected, actual);
}

// Test lowercase characters.
void	test_ft_isalpha_lower(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = 'h';
	expected = isalpha(c);
	actual = ft_isalpha(c);
	assert_eq(expected, actual);
}

// Test digit characters.
void	test_ft_isalpha_digit(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '9';
	expected = isalpha(c);
	actual = ft_isalpha(c);
	assert_eq(expected, actual);
}

// Test symbol characters.
void	test_ft_isalpha_symbol(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '@';
	expected = isalpha(c);
	actual = ft_isalpha(c);
	assert_eq(expected, actual);
}

// Test punctuation characters.
void	test_ft_isalpha_punctuation(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '.';
	expected = isalpha(c);
	actual = ft_isalpha(c);
	assert_eq(expected, actual);
}

// Test whitespace characters.
void	test_ft_isalpha_whitespace(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = ' ';
	expected = isalpha(c);
	actual = ft_isalpha(c);
	assert_eq(expected, actual);
}

// Test boundery characters.
void	test_ft_isalpha_boundery(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '`';
	expected = isalpha(c);
	actual = ft_isalpha(c);
	assert_eq(expected, actual);
}

// Test non-ASCII characters.
void	test_ft_isalpha_non_ascii(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = -87;
	expected = isalpha(c);
	actual = ft_isalpha(c);
	assert_eq(expected, actual);
}

// Test special characters.
void	test_ft_isalpha_special(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = EOF;
	expected = isalpha(c);
	actual = ft_isalpha(c);
	assert_eq(expected, actual);
}

// Test null characters.
void	test_ft_isalpha_null(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '\0';
	expected = isalpha(c);
	actual = ft_isalpha(c);
	assert_eq(expected, actual);
}

// Test extended characters.
void	test_ft_isalpha_extended(void)
{
	char	c;
	int		start;
	int		end;
	size_t	expected;
	size_t	actual;

	start = 128;
	end = 255;
	while (start <= end)
	{
		c = start;
		expected = isalpha(c);
		actual = ft_isalpha(c);
		if (expected != actual)
			assert_eq(expected, actual);
		start++;
	}
	assert_eq(expected, actual);
}

int	main(void)
{
	run_test(test_ft_isalpha_upper, "ft_isalpha_upper");
	run_test(test_ft_isalpha_lower, "ft_isalpha_lower");
	run_test(test_ft_isalpha_digit, "ft_isalpha_digit");
	run_test(test_ft_isalpha_symbol, "ft_isalpha_symbol");
	run_test(test_ft_isalpha_punctuation, "ft_isalpha_punctuation");
	run_test(test_ft_isalpha_whitespace, "ft_isalpha_whitespace");
	run_test(test_ft_isalpha_boundery, "ft_isalpha_boundery");
	run_test(test_ft_isalpha_non_ascii, "ft_isalpha_non_ascii");
	run_test(test_ft_isalpha_special, "ft_isalpha_special");
	run_test(test_ft_isalpha_null, "ft_isalpha_null");
	run_test(test_ft_isalpha_extended, "ft_isalpha_extended");
	return (0);
}
 */