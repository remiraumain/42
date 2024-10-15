/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:26:35 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/15 10:32:53 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <ctype.h>

// Test uppercase characters.
void	test_ft_toupper_upper(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = 'H';
	expected = toupper(c);
	actual = ft_toupper(c);
	ASSERT_EQ(expected, actual);
}

// Test lowercase characters.
void	test_ft_toupper_lower(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = 'h';
	expected = toupper(c);
	actual = ft_toupper(c);
	ASSERT_EQ(expected, actual);
}

// Test digit characters.
void	test_ft_toupper_digit(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '9';
	expected = toupper(c);
	actual = ft_toupper(c);
	ASSERT_EQ(expected, actual);
}

// Test symbol characters.
void	test_ft_toupper_symbol(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '@';
	expected = toupper(c);
	actual = ft_toupper(c);
	ASSERT_EQ(expected, actual);
}

// Test punctuation characters.
void	test_ft_toupper_punctuation(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '.';
	expected = toupper(c);
	actual = ft_toupper(c);
	ASSERT_EQ(expected, actual);
}

// Test whitespace characters.
void	test_ft_toupper_whitespace(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = ' ';
	expected = toupper(c);
	actual = ft_toupper(c);
	ASSERT_EQ(expected, actual);
}

// Test boundery characters.
void	test_ft_toupper_boundery(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '`';
	expected = toupper(c);
	actual = ft_toupper(c);
	ASSERT_EQ(expected, actual);
}

// Test non-ASCII characters.
void	test_ft_toupper_non_ascii(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = -87;
	expected = toupper(c);
	actual = ft_toupper(c);
	ASSERT_EQ(expected, actual);
}

// Test special characters.
void	test_ft_toupper_special(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = EOF;
	expected = toupper(c);
	actual = ft_toupper(c);
	ASSERT_EQ(expected, actual);
}

// Test null characters.
void	test_ft_toupper_null(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '\0';
	expected = toupper(c);
	actual = ft_toupper(c);
	ASSERT_EQ(expected, actual);
}

// Test extended characters.
void	test_ft_toupper_extended(void)
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
		expected = toupper(c);
		actual = ft_toupper(c);
		if (expected != actual)
			ASSERT_EQ(expected, actual);
		start++;
	}
	ASSERT_EQ(expected, actual);
}

int	main(void)
{
	RUN_TEST(test_ft_toupper_upper, "ft_toupper_upper");
	RUN_TEST(test_ft_toupper_lower, "ft_toupper_lower");
	RUN_TEST(test_ft_toupper_digit, "ft_toupper_digit");
	RUN_TEST(test_ft_toupper_symbol, "ft_toupper_symbol");
	RUN_TEST(test_ft_toupper_punctuation, "ft_toupper_punctuation");
	RUN_TEST(test_ft_toupper_whitespace, "ft_toupper_whitespace");
	RUN_TEST(test_ft_toupper_boundery, "ft_toupper_boundery");
	RUN_TEST(test_ft_toupper_non_ascii, "ft_toupper_non_ascii");
	RUN_TEST(test_ft_toupper_special, "ft_toupper_special");
	RUN_TEST(test_ft_toupper_null, "ft_toupper_null");
	RUN_TEST(test_ft_toupper_extended, "ft_toupper_extended");
	return (0);
}
 */