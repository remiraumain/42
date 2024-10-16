/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:58:31 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 16:23:46 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <string.h>

// Test de base où le sous-chaîne est présente au milieu.
void	test_ft_strstr_basic(void)
{
	const char	*haystack_std = "Hello, World!";
	const char	*needle_std = "World";
	const char	*result_std = strstr(haystack_std, needle_std);
	const char	*result_custom = ft_strstr(haystack_std, needle_std);

	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std && result_custom)
	{
		assert_eq(strcmp(result_std, result_custom), 0);
	}
}

// Test où le sous-chaîne est au début.
void	test_ft_strstr_at_start(void)
{
	const char	*haystack_std = "Hello, World!";
	const char	*needle_std = "Hello";
	const char	*result_std = strstr(haystack_std, needle_std);
	const char	*result_custom = ft_strstr(haystack_std, needle_std);

	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std && result_custom)
	{
		assert_eq(strcmp(result_std, result_custom), 0);
	}
}

// Test où le sous-chaîne est à la fin.
void	test_ft_strstr_at_end(void)
{
	const char	*haystack_std = "Hello, World!";
	const char	*needle_std = "World!";
	const char	*result_std = strstr(haystack_std, needle_std);
	const char	*result_custom = ft_strstr(haystack_std, needle_std);

	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std && result_custom)
	{
		assert_eq(strcmp(result_std, result_custom), 0);
	}
}

// Test où le sous-chaîne n'est pas présent.
void	test_ft_strstr_not_found(void)
{
	const char	*haystack_std = "Hello, World!";
	const char	*needle_std = "Universe";
	const char	*result_std = strstr(haystack_std, needle_std);
	const char	*result_custom = ft_strstr(haystack_std, needle_std);

	assert_eq((result_std == NULL), (result_custom == NULL));
}

// Test avec une sous-chaîne vide.
void	test_ft_strstr_empty_needle(void)
{
	const char	*haystack_std = "Hello, World!";
	const char	*needle_std = "";
	const char	*result_std = strstr(haystack_std, needle_std);
	const char	*result_custom = ft_strstr(haystack_std, needle_std);

	assert_eq(result_std == haystack_std, result_custom == haystack_std);
}

// Test avec un haystack vide.
void	test_ft_strstr_empty_haystack(void)
{
	const char	*haystack_std = "";
	const char	*needle_std = "Hello";
	const char	*result_std = strstr(haystack_std, needle_std);
	const char	*result_custom = ft_strstr(haystack_std, needle_std);

	assert_eq((result_std == NULL), (result_custom == NULL));
}

// Test avec les deux haystack et needle vides.
void	test_ft_strstr_both_empty(void)
{
	const char	*haystack_std = "";
	const char	*needle_std = "";
	const char	*result_std = strstr(haystack_std, needle_std);
	const char	*result_custom = ft_strstr(haystack_std, needle_std);

	assert_eq(result_std == haystack_std, result_custom == haystack_std);
}

// Test avec des caractères spéciaux.
void	test_ft_strstr_special_characters(void)
{
	const char	*haystack_std = "Hello, W@rld!";
	const char	*needle_std = "W@rld";
	const char	*result_std = strstr(haystack_std, needle_std);
	const char	*result_custom = ft_strstr(haystack_std, needle_std);

	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std && result_custom)
	{
		assert_eq(strcmp(result_std, result_custom), 0);
	}
}

// Test avec des caractères répétés.
void	test_ft_strstr_repeated_characters(void)
{
	const char	*haystack_std = "aaabaaaab";
	const char	*needle_std = "aaab";
	const char	*result_std = strstr(haystack_std, needle_std);
	const char	*result_custom = ft_strstr(haystack_std, needle_std);

	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std && result_custom)
	{
		assert_eq(strcmp(result_std, result_custom), 0);
	}
}

// Test avec des NULL dans le haystack (si applicable).
void	test_ft_strstr_null_in_haystack(void)
{
	char		haystack_with_null[] = "Hello\0World";
	const char	*needle_std = "World";
	const char	*result_std = strstr(haystack_with_null, needle_std);
	const char	*result_custom = ft_strstr(haystack_with_null, needle_std);

	assert_eq((result_std == NULL), (result_custom == NULL));
}

int	main(void)
{
	run_test(test_ft_strstr_basic, "ft_strstr_basic");
	run_test(test_ft_strstr_at_start, "ft_strstr_at_start");
	run_test(test_ft_strstr_at_end, "ft_strstr_at_end");
	run_test(test_ft_strstr_not_found, "ft_strstr_not_found");
	run_test(test_ft_strstr_empty_needle, "ft_strstr_empty_needle");
	run_test(test_ft_strstr_empty_haystack, "ft_strstr_empty_haystack");
	run_test(test_ft_strstr_both_empty, "ft_strstr_both_empty");
	run_test(test_ft_strstr_special_characters, "ft_strstr_special_characters");
	run_test(test_ft_strstr_repeated_characters,
		"ft_strstr_repeated_characters");
	run_test(test_ft_strstr_null_in_haystack, "ft_strstr_null_in_haystack");
	return (0);
}
 */