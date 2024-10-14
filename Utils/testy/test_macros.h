/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_macros.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:48:28 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/11 11:13:42 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MACROS_H
# define TEST_MACROS_H

# include <stdio.h>

void	run_test(void (*test)(void), const char *test_name);

/**
 * @brief Defines a test function.
 *
 * This macro simplifies the declaration of a test function. It defines a
 *  function with the specified name that takes no arguments.
 *
 * @param name The name of the test function.
 *
 * @note Use the `RUN_TEST` macro to execute the test function.
 *
 * @code
 * --- Example usage ---
 *
 * TEST(my_test_function)
 * {
 *     // Your test code here
 * }
 * @endcode
 */
# define TEST(name) void name(void)

/**
 * @brief Runs a test function and displays its name.
 *
 * This macro is used to execute a test function that was defined using the
 *  `TEST` macro. It prints the name of the test before executing it, which
 *  helps in tracking test execution.
 *
 * @param test The test function to run.
 * @param test_name The name of the test function to run.
 *
 * @code
 * --- Example usage ---
 *
 * int main(void)
 * {
 *     RUN_TEST(my_test_function, my_test_function_name);
 *     return (0);
 * }
 * @endcode
 */
# define RUN_TEST(test, test_name) run_test(test, test_name)

#endif
