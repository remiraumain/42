/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:02:46 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 18:44:01 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <string.h>

// Test de base où le caractère est présent au milieu de la chaîne.
void	test_ft_strrchr_basic(void)
{
	const char	*haystack_std = "Hello, World!";
	int			c_std;
	char		*result_std;
	char		*result_custom;

	c_std = 'o';
	result_std = strrchr(haystack_std, c_std);
	result_custom = ft_strrchr(haystack_std, c_std);
	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std && result_custom)
	{
		assert_eq(strcmp(result_std, result_custom), 0);
	}
}

// Test où le caractère est au début de la chaîne.
void	test_ft_strrchr_at_start(void)
{
	const char	*haystack_std = "Hello, World!";
	int			c_std;
	char		*result_std;
	char		*result_custom;

	c_std = 'H';
	result_std = strrchr(haystack_std, c_std);
	result_custom = ft_strrchr(haystack_std, c_std);
	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std && result_custom)
	{
		assert_eq(strcmp(result_std, result_custom), 0);
	}
}

// Test où le caractère est à la fin de la chaîne.
void	test_ft_strrchr_at_end(void)
{
	const char	*haystack_std = "Hello, World!";
	int			c_std;
	char		*result_std;
	char		*result_custom;

	c_std = '!';
	result_std = strrchr(haystack_std, c_std);
	result_custom = ft_strrchr(haystack_std, c_std);
	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std && result_custom)
	{
		assert_eq(strcmp(result_std, result_custom), 0);
	}
}

// Test où le caractère n'est pas présent dans la chaîne.
void	test_ft_strrchr_not_found(void)
{
	const char	*haystack_std = "Hello, World!";
	int			c_std;
	char		*result_std;
	char		*result_custom;

	c_std = 'Z';
	result_std = strrchr(haystack_std, c_std);
	result_custom = ft_strrchr(haystack_std, c_std);
	assert_eq((result_std == NULL), (result_custom == NULL));
}

// Test avec le caractère null '\0'.
void	test_ft_strrchr_null_char(void)
{
	const char	*haystack_std = "Hello, World!";
	int			c_std;
	char		*result_std;
	char		*result_custom;

	c_std = '\0';
	result_std = strrchr(haystack_std, c_std);
	result_custom = ft_strrchr(haystack_std, c_std);
	assert_eq((result_std == haystack_std + strlen(haystack_std)),
		(result_custom == haystack_std + strlen(haystack_std)));
}

// Test avec une chaîne vide.
void	test_ft_strrchr_empty_haystack(void)
{
	const char	*haystack_std = "";
	int			c_std;
	char		*result_std;
	char		*result_custom;

	c_std = 'A';
	result_std = strrchr(haystack_std, c_std);
	result_custom = ft_strrchr(haystack_std, c_std);
	assert_eq((result_std == NULL), (result_custom == NULL));
}

// Test avec une sous-chaîne contenant des caractères répétés.
void	test_ft_strrchr_repeated_characters(void)
{
	const char	*haystack_std = "aaabaaaab";
	int			c_std;
	char		*result_std;
	char		*result_custom;

	c_std = 'a';
	result_std = strrchr(haystack_std, c_std);
	result_custom = ft_strrchr(haystack_std, c_std);
	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std && result_custom)
	{
		assert_eq(strcmp(result_std, result_custom), 0);
	}
}

// Test avec des caractères spéciaux.
void	test_ft_strrchr_special_characters(void)
{
	const char	*haystack_std = "Hello, W@rld@!";
	int			c_std;
	char		*result_std;
	char		*result_custom;

	c_std = '@';
	result_std = strrchr(haystack_std, c_std);
	result_custom = ft_strrchr(haystack_std, c_std);
	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std && result_custom)
	{
		assert_eq(strcmp(result_std, result_custom), 0);
	}
}

// Test avec des caractères non-ASCII.
void	test_ft_strrchr_non_ascii_characters(void)
{
	const char	*haystack_std = "Café Münchner Kindl";
	int			c_std;
	char		*result_std;
	char		*result_custom;

	c_std = -15447;
	result_std = strrchr(haystack_std, c_std);
	result_custom = ft_strrchr(haystack_std, c_std);
	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std && result_custom)
	{
		assert_eq(strcmp(result_std, result_custom), 0);
	}
}

// Test où haystack contient des caractères nulls avant la fin.
void	test_ft_strrchr_null_bytes_in_haystack(void)
{
	char	haystack_with_null[] = "Hello\0World!";
	int		c_std;
	char	*result_std;
	char	*result_custom;

	c_std = 'W';
	result_std = strrchr(haystack_with_null, c_std);
	result_custom = ft_strrchr(haystack_with_null, c_std);
	assert_eq((result_std == NULL), (result_custom == NULL));
}

// Test où c est un caractère qui apparaît plusieurs fois.
void	test_ft_strrchr_multiple_occurrences(void)
{
	const char	*haystack_std = "This is a test string.";
	int			c_std;
	char		*result_std;
	char		*result_custom;

	c_std = 't';
	result_std = strrchr(haystack_std, c_std);
	result_custom = ft_strrchr(haystack_std, c_std);
	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std && result_custom)
	{
		assert_eq(strcmp(result_std, result_custom), 0);
	}
}

// Test avec des majuscules et minuscules.
void	test_ft_strrchr_case_sensitive(void)
{
	const char	*haystack_std = "Hello, World! hello, world!";
	int			c_std;
	char		*result_std;
	char		*result_custom;

	c_std = 'H';
	result_std = strrchr(haystack_std, c_std);
	result_custom = ft_strrchr(haystack_std, c_std);
	assert_eq((result_std == haystack_std), (result_custom == haystack_std));
}

// Test avec c ne correspondant pas à un caractère.
void	test_ft_strrchr_not_a_character(void)
{
	const char	*haystack_std = "Hello, World!";
	int			c_std;
	char		*result_std;
	char		*result_custom;

	c_std = 'X';
	result_std = strrchr(haystack_std, c_std);
	result_custom = ft_strrchr(haystack_std, c_std);
	assert_eq((result_std == NULL), (result_custom == NULL));
}

int	main(void)
{
	run_test(test_ft_strrchr_basic, "ft_strrchr_basic");
	run_test(test_ft_strrchr_at_start, "ft_strrchr_at_start");
	run_test(test_ft_strrchr_at_end, "ft_strrchr_at_end");
	run_test(test_ft_strrchr_not_found, "ft_strrchr_not_found");
	run_test(test_ft_strrchr_null_char, "ft_strrchr_null_char");
	run_test(test_ft_strrchr_empty_haystack, "ft_strrchr_empty_haystack");
	run_test(test_ft_strrchr_repeated_characters,
		"ft_strrchr_repeated_characters");
	run_test(test_ft_strrchr_special_characters,
		"ft_strrchr_special_characters");
	run_test(test_ft_strrchr_non_ascii_characters,
		"ft_strrchr_non_ascii_characters");
	run_test(test_ft_strrchr_null_bytes_in_haystack,
		"ft_strrchr_null_bytes_in_haystack");
	run_test(test_ft_strrchr_multiple_occurrences,
		"ft_strrchr_multiple_occurrences");
	run_test(test_ft_strrchr_case_sensitive, "ft_strrchr_case_sensitive");
	run_test(test_ft_strrchr_not_a_character, "ft_strrchr_not_a_character");
	return (0);
}
 */