/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:09:11 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 20:30:33 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <stdlib.h>
#include <string.h>

// Test de base où le caractère est présent au milieu de la chaîne.
void	test_ft_memchr_basic(void)
{
	const char	*haystack_std = "Hello, World!";
	int			c_std;
	size_t		n;
	char		*result_std;
	char		*result_custom;

	c_std = 'W';
	n = strlen(haystack_std) + 1;
	result_std = memchr(haystack_std, c_std, n);
	result_custom = ft_memchr(haystack_std, c_std, n);
	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std != NULL && result_custom != NULL)
	{
		assert_eq(result_std - haystack_std, result_custom - haystack_std);
	}
}

// Test où le caractère n'est pas présent dans la chaîne.
void	test_ft_memchr_not_found(void)
{
	const char	*haystack_std = "Hello, World!";
	int			c_std;
	size_t		n;
	char		*result_std;
	char		*result_custom;

	c_std = 'Z';
	n = strlen(haystack_std) + 1;
	result_std = memchr(haystack_std, c_std, n);
	result_custom = ft_memchr(haystack_std, c_std, n);
	assert_eq((result_std == NULL), (result_custom == NULL));
}

// Test où le caractère est au début de la chaîne.
void	test_ft_memchr_at_start(void)
{
	const char	*haystack_std = "Hello, World!";
	int			c_std;
	size_t		n;
	char		*result_std;
	char		*result_custom;

	c_std = 'H';
	n = strlen(haystack_std) + 1;
	result_std = memchr(haystack_std, c_std, n);
	result_custom = ft_memchr(haystack_std, c_std, n);
	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std != NULL && result_custom != NULL)
	{
		assert_eq(result_std - haystack_std, result_custom - haystack_std);
	}
}

// Test où le caractère est à la fin de la chaîne.
void	test_ft_memchr_at_end(void)
{
	const char	*haystack_std = "Hello, World!";
	int			c_std;
	size_t		n;
	char		*result_std;
	char		*result_custom;

	c_std = '!';
	n = strlen(haystack_std) + 1;
	result_std = memchr(haystack_std, c_std, n);
	result_custom = ft_memchr(haystack_std, c_std, n);
	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std != NULL && result_custom != NULL)
	{
		assert_eq(result_std - haystack_std, result_custom - haystack_std);
	}
}

// Test avec le caractère null '\0'.
void	test_ft_memchr_null_char(void)
{
	const char	*haystack_std = "Hello, World!";
	int			c_std;
	size_t		n;
	char		*result_std;
	char		*result_custom;

	c_std = '\0';
	n = strlen(haystack_std) + 1;
	result_std = memchr(haystack_std, c_std, n);
	result_custom = ft_memchr(haystack_std, c_std, n);
	assert_eq((result_std == (haystack_std + strlen(haystack_std))),
		(result_custom == (haystack_std + strlen(haystack_std))));
}

// Test avec une chaîne vide.
void	test_ft_memchr_empty_buffer(void)
{
	const char	*haystack_std = "";
	int			c_std;
	size_t		n;
	char		*result_std;
	char		*result_custom;

	c_std = 'A';
	n = 0;
	result_std = memchr(haystack_std, c_std, n);
	result_custom = ft_memchr(haystack_std, c_std, n);
	assert_eq((result_std == NULL), (result_custom == NULL));
}

// Test avec n = 0 (aucune comparaison).
void	test_ft_memchr_zero_n(void)
{
	const char	*haystack_std = "Hello, World!";
	int			c_std;
	size_t		n;
	char		*result_std;
	char		*result_custom;

	c_std = 'W';
	n = 0;
	result_std = memchr(haystack_std, c_std, n);
	result_custom = ft_memchr(haystack_std, c_std, n);
	assert_eq((result_std == NULL), (result_custom == NULL));
}

// Test avec plusieurs occurrences du caractère.
void	test_ft_memchr_multiple_occurrences(void)
{
	const char	*haystack_std = "abacadabra";
	int			c_std;
	size_t		n;
	char		*result_std;
	char		*result_custom;

	c_std = 'a';
	n = strlen(haystack_std) + 1;
	result_std = memchr(haystack_std, c_std, n);
	result_custom = ft_memchr(haystack_std, c_std, n);
	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std != NULL && result_custom != NULL)
	{
		assert_eq(result_std - haystack_std, result_custom - haystack_std);
	}
}

// Test avec des caractères spéciaux.
void	test_ft_memchr_special_characters(void)
{
	const char	*haystack_std = "Hello, W@rld@!";
	int			c_std;
	size_t		n;
	char		*result_std;
	char		*result_custom;

	c_std = '@';
	n = strlen(haystack_std) + 1;
	result_std = memchr(haystack_std, c_std, n);
	result_custom = ft_memchr(haystack_std, c_std, n);
	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std != NULL && result_custom != NULL)
	{
		assert_eq(result_std - haystack_std, result_custom - haystack_std);
	}
}

// Test avec des caractères non-ASCII.
void	test_ft_memchr_non_ascii_characters(void)
{
	const char	*haystack_std = "Café Münchner Kindl";
	int			c_std;
	size_t		n;
	char		*result_std;
	char		*result_custom;

	c_std = -15447;
	n = strlen(haystack_std) + 1;
	result_std = memchr(haystack_std, c_std, n);
	result_custom = ft_memchr(haystack_std, c_std, n);
	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std != NULL && result_custom != NULL)
	{
		assert_eq(result_std - haystack_std, result_custom - haystack_std);
	}
}

// Test avec des caractères nulls dans le buffer.
void	test_ft_memchr_with_null_bytes(void)
{
	char	haystack_with_null[] = "Hello\0World!";
	int		c_std;
	size_t	n;
	char	*result_std;
	char	*result_custom;

	c_std = 'W';
	n = sizeof(haystack_with_null);
	result_std = memchr(haystack_with_null, c_std, n);
	result_custom = ft_memchr(haystack_with_null, c_std, n);
	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std != NULL && result_custom != NULL)
	{
		assert_eq(result_std - haystack_with_null, result_custom
			- haystack_with_null);
	}
}

// Test avec un grand buffer.
void	test_ft_memchr_large_buffer(void)
{
	size_t	n;
	char	*haystack_std;
	char	*haystack_custom;
	int		c_std;
	char	*result_std;
	char	*result_custom;

	n = 1024;
	haystack_std = malloc(n);
	haystack_custom = malloc(n);
	if (!haystack_std || !haystack_custom)
	{
		assert_eq(1, 0);
		return ;
	}
	memset(haystack_std, 'A', n);
	memset(haystack_custom, 'A', n);
	haystack_std[n - 10] = 'B';
	haystack_custom[n - 10] = 'B';
	c_std = 'B';
	result_std = memchr(haystack_std, c_std, n);
	result_custom = ft_memchr(haystack_custom, c_std, n);
	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std != NULL && result_custom != NULL)
	{
		assert_eq(result_std - haystack_std, result_custom - haystack_custom);
	}
	free(haystack_std);
	free(haystack_custom);
}

// Test avec des données binaires.
void	test_ft_memchr_binary_data(void)
{
	int				c_std;
	size_t			n;
	unsigned char	*result_std;
	unsigned char	*result_custom;

	unsigned char	haystack_std[] = {0x00, 0xFF, 0xAB, 0xCD, 0xEF, 0x01, 0x02,
			0x03};
	unsigned char	haystack_custom[] = {0x00, 0xFF, 0xAB, 0xCD, 0xEF, 0x01,
			0x02, 0x03};
	c_std = 0xCD;
	n = sizeof(haystack_std);
	result_std = memchr(haystack_std, c_std, n);
	result_custom = ft_memchr(haystack_custom, c_std, n);
	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std != NULL && result_custom != NULL)
	{
		assert_eq(result_std - haystack_std, result_custom - haystack_custom);
	}
}

// Test où le caractère apparaît plusieurs fois.
void	test_ft_memchr_multiple_occurrences_in_buffer(void)
{
	const char	*haystack_std = "abacadabra";
	int			c_std;
	size_t		n;
	char		*result_std;
	char		*result_custom;

	c_std = 'a';
	n = strlen(haystack_std) + 1;
	result_std = memchr(haystack_std, c_std, n);
	result_custom = ft_memchr(haystack_std, c_std, n);
	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std != NULL && result_custom != NULL)
	{
		assert_eq(result_std - haystack_std, result_custom - haystack_std);
	}
}

int	main(void)
{
	run_test(test_ft_memchr_basic, "ft_memchr_basic");
	run_test(test_ft_memchr_not_found, "ft_memchr_not_found");
	run_test(test_ft_memchr_at_start, "ft_memchr_at_start");
	run_test(test_ft_memchr_at_end, "ft_memchr_at_end");
	run_test(test_ft_memchr_null_char, "ft_memchr_null_char");
	run_test(test_ft_memchr_empty_buffer, "ft_memchr_empty_buffer");
	run_test(test_ft_memchr_zero_n, "ft_memchr_zero_n");
	run_test(test_ft_memchr_multiple_occurrences,
		"ft_memchr_multiple_occurrences");
	run_test(test_ft_memchr_special_characters, "ft_memchr_special_characters");
	run_test(test_ft_memchr_non_ascii_characters,
		"ft_memchr_non_ascii_characters");
	run_test(test_ft_memchr_with_null_bytes, "ft_memchr_with_null_bytes");
	run_test(test_ft_memchr_large_buffer, "ft_memchr_large_buffer");
	run_test(test_ft_memchr_binary_data, "ft_memchr_binary_data");
	run_test(test_ft_memchr_multiple_occurrences_in_buffer,
		"ft_memchr_multiple_occurrences_in_buffer");
	return (0);
}
 */