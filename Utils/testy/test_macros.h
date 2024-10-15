/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_macros.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:48:28 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/15 07:45:50 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MACROS_H
# define TEST_MACROS_H

void	run_test(void (*test)(void), const char *test_name);

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
