/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:06:52 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 12:21:05 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <ctype.h>

// Test uppercase characters.
void	test_ft_tolower_upper(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = 'H';
	expected = tolower(c);
	actual = ft_tolower(c);
	assert_eq(expected, actual);
}

// Test lowercase characters.
void	test_ft_tolower_lower(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = 'h';
	expected = tolower(c);
	actual = ft_tolower(c);
	assert_eq(expected, actual);
}

// Test digit characters.
void	test_ft_tolower_digit(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '9';
	expected = tolower(c);
	actual = ft_tolower(c);
	assert_eq(expected, actual);
}

// Test symbol characters.
void	test_ft_tolower_symbol(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '@';
	expected = tolower(c);
	actual = ft_tolower(c);
	assert_eq(expected, actual);
}

// Test punctuation characters.
void	test_ft_tolower_punctuation(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '.';
	expected = tolower(c);
	actual = ft_tolower(c);
	assert_eq(expected, actual);
}

// Test whitespace characters.
void	test_ft_tolower_whitespace(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = ' ';
	expected = tolower(c);
	actual = ft_tolower(c);
	assert_eq(expected, actual);
}

// Test boundery characters.
void	test_ft_tolower_boundery(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '`';
	expected = tolower(c);
	actual = ft_tolower(c);
	assert_eq(expected, actual);
}

// Test non-ASCII characters.
void	test_ft_tolower_non_ascii(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = -87;
	expected = tolower(c);
	actual = ft_tolower(c);
	assert_eq(expected, actual);
}

// Test special characters.
void	test_ft_tolower_special(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = EOF;
	expected = tolower(c);
	actual = ft_tolower(c);
	assert_eq(expected, actual);
}

// Test null characters.
void	test_ft_tolower_null(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '\0';
	expected = tolower(c);
	actual = ft_tolower(c);
	assert_eq(expected, actual);
}

// Test extended characters.
void	test_ft_tolower_extended(void)
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
		expected = tolower(c);
		actual = ft_tolower(c);
		if (expected != actual)
			assert_eq(expected, actual);
		start++;
	}
	assert_eq(expected, actual);
}

int	main(void)
{
	run_test(test_ft_tolower_upper, "ft_tolower_upper");
	run_test(test_ft_tolower_lower, "ft_tolower_lower");
	run_test(test_ft_tolower_digit, "ft_tolower_digit");
	run_test(test_ft_tolower_symbol, "ft_tolower_symbol");
	run_test(test_ft_tolower_punctuation, "ft_tolower_punctuation");
	run_test(test_ft_tolower_whitespace, "ft_tolower_whitespace");
	run_test(test_ft_tolower_boundery, "ft_tolower_boundery");
	run_test(test_ft_tolower_non_ascii, "ft_tolower_non_ascii");
	run_test(test_ft_tolower_special, "ft_tolower_special");
	run_test(test_ft_tolower_null, "ft_tolower_null");
	run_test(test_ft_tolower_extended, "ft_tolower_extended");
	return (0);
}
 */