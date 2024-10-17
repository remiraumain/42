/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 06:14:38 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/17 06:29:05 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <string.h>

// Test de base avec des chaînes égales et n < longueur des chaînes.
void	test_ft_memcmp_equal_strings(void)
{
	const char	*s1 = "HelloWorld";
	const char	*s2 = "HelloWorld";
	size_t		n;
	int			std_result;
	int			custom_result;

	n = 5;
	std_result = memcmp(s1, s2, n);
	custom_result = ft_memcmp(s1, s2, n);
	assert_eq(std_result, custom_result);
}

// Test avec des chaînes différentes et n < point de différence.
void	test_ft_memcmp_different_strings_less_n(void)
{
	const char	*s1 = "HelloWorld";
	const char	*s2 = "HelloXorld";
	size_t		n;
	int			std_result;
	int			custom_result;

	n = 6;
	std_result = memcmp(s1, s2, n);
	custom_result = ft_memcmp(s1, s2, n);
	assert_eq(std_result, custom_result);
}

// Test avec des chaînes différentes et n > point de différence.
void	test_ft_memcmp_different_strings_more_n(void)
{
	const char	*s1 = "HelloWorld";
	const char	*s2 = "HelloXorld";
	size_t		n;
	int			std_result;
	int			custom_result;

	n = 10;
	std_result = memcmp(s1, s2, n);
	custom_result = ft_memcmp(s1, s2, n);
	assert_eq(std_result, custom_result);
}

// Test avec n = 0 (aucune comparaison).
void	test_ft_memcmp_zero_n(void)
{
	const char	*s1 = "HelloWorld";
	const char	*s2 = "GoodbyeWorld";
	size_t		n;
	int			std_result;
	int			custom_result;

	n = 0;
	std_result = memcmp(s1, s2, n);
	custom_result = ft_memcmp(s1, s2, n);
	assert_eq(std_result, custom_result);
}

// Test où une chaîne est un sous-ensemble de l'autre.
void	test_ft_memcmp_substring(void)
{
	const char	*s1 = "Hello";
	const char	*s2 = "HelloWorld";
	size_t		n;
	int			std_result;
	int			custom_result;

	n = 10;
	std_result = memcmp(s1, s2, n);
	custom_result = ft_memcmp(s1, s2, n);
	assert_eq(std_result, custom_result);
}

// Test avec des chaînes vides.
void	test_ft_memcmp_empty_strings(void)
{
	const char	*s1 = "";
	const char	*s2 = "";
	size_t		n;
	int			std_result;
	int			custom_result;

	n = 5;
	std_result = memcmp(s1, s2, n);
	custom_result = ft_memcmp(s1, s2, n);
	assert_eq(std_result, custom_result);
}

// Test avec une chaîne vide et une chaîne non vide.
void	test_ft_memcmp_one_empty_string(void)
{
	const char	*s1 = "";
	const char	*s2 = "NonEmpty";
	size_t		n;
	int			std_result;
	int			custom_result;

	n = 5;
	std_result = memcmp(s1, s2, n);
	custom_result = ft_memcmp(s1, s2, n);
	assert_eq(std_result, custom_result);
}

// Test avec des caractères spéciaux.
void	test_ft_memcmp_special_characters(void)
{
	const char	*s1 = "Hello, @World!";
	const char	*s2 = "Hello, #World!";
	size_t		n;
	int			std_result;
	int			custom_result;

	n = 7;
	std_result = memcmp(s1, s2, n);
	custom_result = ft_memcmp(s1, s2, n);
	assert_eq(std_result, custom_result);
}

int	main(void)
{
	run_test(test_ft_memcmp_equal_strings, "ft_memcmp_equal_strings");
	run_test(test_ft_memcmp_different_strings_less_n,
		"ft_memcmp_different_strings_less_n");
	run_test(test_ft_memcmp_different_strings_more_n,
		"ft_memcmp_different_strings_more_n");
	run_test(test_ft_memcmp_zero_n, "ft_memcmp_zero_n");
	run_test(test_ft_memcmp_substring, "ft_memcmp_substring");
	run_test(test_ft_memcmp_empty_strings, "ft_memcmp_empty_strings");
	run_test(test_ft_memcmp_one_empty_string, "ft_memcmp_one_empty_string");
	run_test(test_ft_memcmp_special_characters, "ft_memcmp_special_characters");

	return (0);
}