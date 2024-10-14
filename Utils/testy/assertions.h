/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:24:32 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/10 16:18:04 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSERTIONS_H
# define ASSERTIONS_H

# include <stdio.h>
# include <string.h>

void	assert_eq(int expected, int actual);
void	assert_str_eq(char *expected, char *actual);

/**
 * @brief Check if two integers are equal.
 *
 * This macro checks if the expected value is equal to the actual value.
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
 * ASSERT_EQ(13, ft_strlen("Hello, World!")); // Passes
 *
 * ASSERT_EQ(42, ft_strlen("Hello, World!")); // Fails
 * @endcode
 */
# define ASSERT_EQ(expected, actual) assert_eq(expected, actual)

/**
 * @brief Check if two strings are equal.
 *
 * This macro checks if the expected value is equal to the actual value.
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
# define ASSERT_STR_EQ(expected, actial) assert_str_eq(expected, actual)

#endif