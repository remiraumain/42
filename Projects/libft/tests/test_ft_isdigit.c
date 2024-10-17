/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:47:33 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 12:21:05 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <ctype.h>

// Test digit characters.
void	test_ft_isdigit_digit(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '9';
	expected = isdigit(c);
	actual = ft_isdigit(c);
	assert_eq(expected, actual);
}

// Test uppercase characters.
void	test_ft_isdigit_upper(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = 'H';
	expected = isdigit(c);
	actual = ft_isdigit(c);
	assert_eq(expected, actual);
}

// Test lowercase characters.
void	test_ft_isdigit_lower(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = 'h';
	expected = isdigit(c);
	actual = ft_isdigit(c);
	assert_eq(expected, actual);
}

// Test symbol characters.
void	test_ft_isdigit_symbol(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '@';
	expected = isdigit(c);
	actual = ft_isdigit(c);
	assert_eq(expected, actual);
}

// Test punctuation characters.
void	test_ft_isdigit_punctuation(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '.';
	expected = isdigit(c);
	actual = ft_isdigit(c);
	assert_eq(expected, actual);
}

// Test whitespace characters.
void	test_ft_isdigit_whitespace(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = ' ';
	expected = isdigit(c);
	actual = ft_isdigit(c);
	assert_eq(expected, actual);
}

// Test boundery characters.
void	test_ft_isdigit_boundery(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '`';
	expected = isdigit(c);
	actual = ft_isdigit(c);
	assert_eq(expected, actual);
}

// Test non-ASCII characters.
void	test_ft_isdigit_non_ascii(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = -87;
	expected = isdigit(c);
	actual = ft_isdigit(c);
	assert_eq(expected, actual);
}

// Test special characters.
void	test_ft_isdigit_special(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = EOF;
	expected = isdigit(c);
	actual = ft_isdigit(c);
	assert_eq(expected, actual);
}

// Test null characters.
void	test_ft_isdigit_null(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '\0';
	expected = isdigit(c);
	actual = ft_isdigit(c);
	assert_eq(expected, actual);
}

// Test extended characters.
void	test_ft_isdigit_extended(void)
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
		expected = isdigit(c);
		actual = ft_isdigit(c);
		if (expected != actual)
			assert_eq(expected, actual);
		start++;
	}
	assert_eq(expected, actual);
}

int	main(void)
{
	run_test(test_ft_isdigit_digit, "ft_isdigit_digit");
	run_test(test_ft_isdigit_upper, "ft_isdigit_upper");
	run_test(test_ft_isdigit_lower, "ft_isdigit_lower");
	run_test(test_ft_isdigit_symbol, "ft_isdigit_symbol");
	run_test(test_ft_isdigit_punctuation, "ft_isdigit_punctuation");
	run_test(test_ft_isdigit_whitespace, "ft_isdigit_whitespace");
	run_test(test_ft_isdigit_boundery, "ft_isdigit_boundery");
	run_test(test_ft_isdigit_non_ascii, "ft_isdigit_non_ascii");
	run_test(test_ft_isdigit_special, "ft_isdigit_special");
	run_test(test_ft_isdigit_null, "ft_isdigit_null");
	run_test(test_ft_isdigit_extended, "ft_isdigit_extended");
	return (0);
}
 */