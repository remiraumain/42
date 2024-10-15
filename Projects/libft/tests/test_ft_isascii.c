/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:39:21 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/15 10:39:46 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <ctype.h>

// Test uppercase characters.
void	test_ft_isascii_upper(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = 'H';
	expected = isascii(c);
	actual = ft_isascii(c);
	ASSERT_EQ(expected, actual);
}

// Test lowercase characters.
void	test_ft_isascii_lower(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = 'h';
	expected = isascii(c);
	actual = ft_isascii(c);
	ASSERT_EQ(expected, actual);
}

// Test digit characters.
void	test_ft_isascii_digit(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '9';
	expected = isascii(c);
	actual = ft_isascii(c);
	ASSERT_EQ(expected, actual);
}

// Test symbol characters.
void	test_ft_isascii_symbol(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '@';
	expected = isascii(c);
	actual = ft_isascii(c);
	ASSERT_EQ(expected, actual);
}

// Test punctuation characters.
void	test_ft_isascii_punctuation(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '.';
	expected = isascii(c);
	actual = ft_isascii(c);
	ASSERT_EQ(expected, actual);
}

// Test whitespace characters.
void	test_ft_isascii_whitespace(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = ' ';
	expected = isascii(c);
	actual = ft_isascii(c);
	ASSERT_EQ(expected, actual);
}

// Test boundery characters.
void	test_ft_isascii_boundery(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '`';
	expected = isascii(c);
	actual = ft_isascii(c);
	ASSERT_EQ(expected, actual);
}

// Test non-ASCII characters.
void	test_ft_isascii_non_ascii(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = -87;
	expected = isascii(c);
	actual = ft_isascii(c);
	ASSERT_EQ(expected, actual);
}

// Test special characters.
void	test_ft_isascii_special(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = EOF;
	expected = isascii(c);
	actual = ft_isascii(c);
	ASSERT_EQ(expected, actual);
}

// Test null characters.
void	test_ft_isascii_null(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '\0';
	expected = isascii(c);
	actual = ft_isascii(c);
	ASSERT_EQ(expected, actual);
}

// Test extended characters.
void	test_ft_isascii_extended(void)
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
		expected = isascii(c);
		actual = ft_isascii(c);
		if (expected != actual)
			ASSERT_EQ(expected, actual);
		start++;
	}
	ASSERT_EQ(expected, actual);
}

int	main(void)
{
	RUN_TEST(test_ft_isascii_upper, "ft_isascii_upper");
	RUN_TEST(test_ft_isascii_lower, "ft_isascii_lower");
	RUN_TEST(test_ft_isascii_digit, "ft_isascii_digit");
	RUN_TEST(test_ft_isascii_symbol, "ft_isascii_symbol");
	RUN_TEST(test_ft_isascii_punctuation, "ft_isascii_punctuation");
	RUN_TEST(test_ft_isascii_whitespace, "ft_isascii_whitespace");
	RUN_TEST(test_ft_isascii_boundery, "ft_isascii_boundery");
	RUN_TEST(test_ft_isascii_non_ascii, "ft_isascii_non_ascii");
	RUN_TEST(test_ft_isascii_special, "ft_isascii_special");
	RUN_TEST(test_ft_isascii_null, "ft_isascii_null");
	RUN_TEST(test_ft_isascii_extended, "ft_isascii_extended");
	return (0);
}