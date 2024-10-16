/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:50:31 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 12:21:05 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

/**
 * @brief Check if two integers are equal.
 *
 * This function checks if the expected value is equal to the actual value.
 * If they are not equal, it prints an error message indicating the
 * file and line number, as well as the expected and actual values.
 *
 * @param expected The expected value (int).
 * @param actual The actual value (int).
 *
 * @note Ensure that both `expected` and `actual` are of compatible types.
 *
 * @code
 * --- Example usage ---
 *
 * assert_eq(13, ft_strlen("Hello, World!")); // Passes
 *
 * assert_eq(42, ft_strlen("Hello, World!")); // Fails
 * @endcode
 */
void	assert_eq(int expected, int actual)
{
	if (expected != actual)
	{
		printf("❌ Expected %d, got %d\n", expected, actual);
	}
	else
	{
		printf("✅ Expected %d, got %d\n", expected, actual);
	}
}

/**
 * @brief Check if two strings are equal.
 *
 * This function checks if the expected value is equal to the actual value.
 * If they are not equal, it prints an error message indicating the
 * file and line number, as well as the expected and actual values.
 *
 * @param expected The expected value (char *).
 * @param actual The actual value (char *).
 *
 * @note Ensure that both `expected` and `actual` are of compatible types.
 *
 * @code
 * --- Example usage ---
 *
 * ASSERT_STR_EQ("Hello, World!", ft_strlen("Hello, World!")); // Passes
 *
 * ASSERT_STR_EQ("Good bye, World!", ft_strlen("Hello, World!")); // Fails
 * @endcode
 */
void	assert_str_eq(char *expected, char *actual)
{
	if (strcmp(expected, actual) != 0)
	{
		printf("❌ Expected %s, got %s\n", expected, actual);
	}
	else
	{
		printf("✅ Expected %s, got %s\n", expected, actual);
	}
}

/**
 * @brief Show an error message if assertion fail
 *
 * This function show on the console an error message.
 *
 * @param message The error message.
 */
void	assert_fail(char *message)
{
	printf("%s", message);
}
