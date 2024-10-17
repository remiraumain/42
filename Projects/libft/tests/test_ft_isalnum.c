/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:35:26 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 12:21:05 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <ctype.h>

// Test uppercase characters.
void	test_ft_isalnum_upper(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = 'H';
	expected = isalnum(c);
	actual = ft_isalnum(c);
	assert_eq(expected, actual);
}

// Test lowercase characters.
void	test_ft_isalnum_lower(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = 'h';
	expected = isalnum(c);
	actual = ft_isalnum(c);
	assert_eq(expected, actual);
}

// Test digit characters.
void	test_ft_isalnum_digit(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '9';
	expected = isalnum(c);
	actual = ft_isalnum(c);
	assert_eq(expected, actual);
}

// Test symbol characters.
void	test_ft_isalnum_symbol(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '@';
	expected = isalnum(c);
	actual = ft_isalnum(c);
	assert_eq(expected, actual);
}

// Test punctuation characters.
void	test_ft_isalnum_punctuation(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '.';
	expected = isalnum(c);
	actual = ft_isalnum(c);
	assert_eq(expected, actual);
}

// Test whitespace characters.
void	test_ft_isalnum_whitespace(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = ' ';
	expected = isalnum(c);
	actual = ft_isalnum(c);
	assert_eq(expected, actual);
}

// Test boundery characters.
void	test_ft_isalnum_boundery(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '`';
	expected = isalnum(c);
	actual = ft_isalnum(c);
	assert_eq(expected, actual);
}

// Test non-ASCII characters.
void	test_ft_isalnum_non_ascii(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = -87;
	expected = isalnum(c);
	actual = ft_isalnum(c);
	assert_eq(expected, actual);
}

// Test special characters.
void	test_ft_isalnum_special(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = EOF;
	expected = isalnum(c);
	actual = ft_isalnum(c);
	assert_eq(expected, actual);
}

// Test null characters.
void	test_ft_isalnum_null(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '\0';
	expected = isalnum(c);
	actual = ft_isalnum(c);
	assert_eq(expected, actual);
}

// Test extended characters.
void	test_ft_isalnum_extended(void)
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
		expected = isalnum(c);
		actual = ft_isalnum(c);
		if (expected != actual)
			assert_eq(expected, actual);
		start++;
	}
	assert_eq(expected, actual);
}

int	main(void)
{
	run_test(test_ft_isalnum_upper, "ft_isalnum_upper");
	run_test(test_ft_isalnum_lower, "ft_isalnum_lower");
	run_test(test_ft_isalnum_digit, "ft_isalnum_digit");
	run_test(test_ft_isalnum_symbol, "ft_isalnum_symbol");
	run_test(test_ft_isalnum_punctuation, "ft_isalnum_punctuation");
	run_test(test_ft_isalnum_whitespace, "ft_isalnum_whitespace");
	run_test(test_ft_isalnum_boundery, "ft_isalnum_boundery");
	run_test(test_ft_isalnum_non_ascii, "ft_isalnum_non_ascii");
	run_test(test_ft_isalnum_special, "ft_isalnum_special");
	run_test(test_ft_isalnum_null, "ft_isalnum_null");
	run_test(test_ft_isalnum_extended, "ft_isalnum_extended");
	return (0);
}
 */