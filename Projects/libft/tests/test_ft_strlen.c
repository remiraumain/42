/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:28:30 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 12:21:05 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <stdlib.h>
#include <string.h>

// Test Standard string.
void	test_ft_strlen_basic(void)
{
	const char	*str;
	size_t		expected;
	size_t		actual;

	str = "Hello, World!";
	expected = strlen(str);
	actual = ft_strlen(str);
	assert_eq(expected, actual);
}

// Test Empty string.
void	test_ft_strlen_empty(void)
{
	const char	*str;
	size_t		expected;
	size_t		actual;

	str = "";
	expected = strlen(str);
	actual = ft_strlen(str);
	assert_eq(expected, actual);
}

// Test one character.
void	test_ft_strlen_only_one(void)
{
	const char	*str;
	size_t		expected;
	size_t		actual;

	str = "A";
	expected = strlen(str);
	actual = ft_strlen(str);
	assert_eq(expected, actual);
}

// Test white spaces.
void	test_ft_strlen_whitespaces(void)
{
	const char	*str;
	size_t		expected;
	size_t		actual;

	str = "     ";
	expected = strlen(str);
	actual = ft_strlen(str);
	assert_eq(expected, actual);
}

// Test special characters.
void	test_ft_strlen_special(void)
{
	const char	*str;
	size_t		expected;
	size_t		actual;

	str = "\n\t\r\b\\\'\"";
	expected = strlen(str);
	actual = ft_strlen(str);
	assert_eq(expected, actual);
}

// Test if stop at null-terminated character.
void	test_ft_strlen_null_terminated(void)
{
	const char	*str;
	size_t		expected;
	size_t		actual;

	str = "He\0llo";
	expected = strlen(str);
	actual = ft_strlen(str);
	assert_eq(expected, actual);
}

// Test counting of UTF-8 multibyte characters.
void	test_ft_strlen_utf8_character(void)
{
	const char	*str;
	size_t		expected;
	size_t		actual;

	str = "Héllo";
	expected = strlen(str);
	actual = ft_strlen(str);
	assert_eq(expected, actual);
}

// Test ft_strlen with a very long string.
void	test_ft_strlen_long_string(void)
{
	char	*str;
	size_t	length;
	size_t	expected;
	size_t	actual;
	size_t	i;

	length = 1000000;
	i = 0;
	str = malloc((length + 1) * sizeof(char));
	if (!str)
	{
		ASSERT_FAIL("Memory allocation failed");
		return ;
	}
	while (i < length)
	{
		str[i] = 'a';
		i++;
	}
	str[length] = '\0';
	expected = strlen(str);
	actual = ft_strlen(str);
	assert_eq(expected, actual);
	free(str);
}

int	main(void)
{
	run_test(test_ft_strlen_basic, "ft_strlen_basic");
	run_test(test_ft_strlen_empty, "ft_strlen_empty");
	run_test(test_ft_strlen_only_one, "ft_strlen_only_one");
	run_test(test_ft_strlen_whitespaces, "ft_strlen_whitespaces");
	run_test(test_ft_strlen_long_string, "ft_strlen_long_string");
	run_test(test_ft_strlen_null_terminated, "ft_strlen_null_terminated");
	run_test(test_ft_strlen_special, "ft_strlen_special");
	run_test(test_ft_strlen_utf8_character, "ft_strlen_utf8_character");
	return (0);
}
 */