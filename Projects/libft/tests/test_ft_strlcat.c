/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:32:31 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 14:32:31 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Test de base pour ft_strlcat.
void	test_ft_strlcat_basic(void)
{
	char	dest_std[20];
	char	dest_custom[20];
	const char	src[] = "World";
	size_t	size;
	size_t	ret_std;
	size_t	ret_custom;

	size = 15;
	memset(dest_std, 'A', 19);
	dest_std[19] = '\0';
	memset(dest_custom, 'A', 19);
	dest_custom[19] = '\0';
	strcpy(dest_std, "Hello ");
	strcpy(dest_custom, "Hello ");
	ret_std = strlcat(dest_std, src, size);
	ret_custom = ft_strlcat(dest_custom, src, size);
	asser_cmp_buf(dest_std, dest_custom, 19);
	assert_eq(ret_std, ret_custom);
}

// Test avec size = 0.
void	test_ft_strlcat_zero_size(void)
{
	char	dest_std[10];
	char	dest_custom[10];
	const char	src[] = "Test";
	size_t	size;
	size_t	ret_std;
	size_t	ret_custom;

	size = 0;
	memset(dest_std, 'B', 9);
	dest_std[9] = '\0';
	memset(dest_custom, 'B', 9);
	dest_custom[9] = '\0';
	ret_std = strlcat(dest_std, src, size);
	ret_custom = ft_strlcat(dest_custom, src, size);
	asser_cmp_buf(dest_std, dest_custom, 9);
	assert_eq(ret_std, ret_custom);
}

// Test de concaténation complète sans troncature.
void	test_ft_strlcat_full_concat(void)
{
	char	dest_std[15];
	char	dest_custom[15];
	const char	src[] = "Concat";
	size_t	size;
	size_t	ret_std;
	size_t	ret_custom;

	size = 15;
	memset(dest_std, 'C', 14);
	dest_std[14] = '\0';
	memset(dest_custom, 'C', 14);
	dest_custom[14] = '\0';
	strcpy(dest_std, "Hello ");
	strcpy(dest_custom, "Hello ");
	ret_std = strlcat(dest_std, src, size);
	ret_custom = ft_strlcat(dest_custom, src, size);
	asser_cmp_buf(dest_std, dest_custom, 14);
	assert_eq(ret_std, ret_custom);
}

// Test avec size insuffisant, entraînant une troncature.
void	test_ft_strlcat_truncate(void)
{
	char	dest_std[10];
	char	dest_custom[10];
	const char	src[] = "Truncate";
	size_t	size;
	size_t	ret_std;
	size_t	ret_custom;

	size = 10;
	memset(dest_std, 'D', 9);
	dest_std[9] = '\0';
	memset(dest_custom, 'D', 9);
	dest_custom[9] = '\0';
	strcpy(dest_std, "Hi ");
	strcpy(dest_custom, "Hi ");
	ret_std = strlcat(dest_std, src, size);
	ret_custom = ft_strlcat(dest_custom, src, size);
	asser_cmp_buf(dest_std, dest_custom, 9);
	assert_eq(ret_std, ret_custom);
}

// Test avec une très grande taille, aucune troncature.
void	test_ft_strlcat_large_size(void)
{
	size_t	size;
	char	*dest_std;
	char	*dest_custom;
	const char	*src;
	size_t	ret_std;
	size_t	ret_custom;

	size = 1024;
	dest_std = malloc(size);
	dest_custom = malloc(size);
	src = "LargeConcat";
	if (!dest_std || !dest_custom)
	{
		assert_eq(1, 0);
		return ;
	}
	memset(dest_std, 'E', size - 1);
	dest_std[size - 1] = '\0';
	memset(dest_custom, 'E', size - 1);
	dest_custom[size - 1] = '\0';
	strcpy(dest_std, "Start ");
	strcpy(dest_custom, "Start ");
	ret_std = strlcat(dest_std, src, size);
	ret_custom = ft_strlcat(dest_custom, src, size);
	asser_cmp_buf(dest_std, dest_custom, size - 1);
	assert_eq(ret_std, ret_custom);
	free(dest_std);
	free(dest_custom);
}

// Test multiple appels de ft_strlcat sur le même buffer.
void	test_ft_strlcat_multiple_calls(void)
{
	char	dest_std[30];
	char	dest_custom[30];
	const char	src1[] = "Hello";
	const char	src2[] = "World";
	size_t	size;
	size_t	ret_std1;
	size_t	ret_custom1;
	size_t	ret_std2;
	size_t	ret_custom2;

	size = 30;
	memset(dest_std, 'F', 29);
	dest_std[29] = '\0';
	memset(dest_custom, 'F', 29);
	dest_custom[29] = '\0';
	strcpy(dest_std, "First ");
	strcpy(dest_custom, "First ");
	ret_std1 = strlcat(dest_std, src1, size);
	ret_custom1 = ft_strlcat(dest_custom, src1, size);
	ret_std2 = strlcat(dest_std, src2, size);
	ret_custom2 = ft_strlcat(dest_custom, src2, size);
	asser_cmp_buf(dest_std, dest_custom, 29);
	assert_eq(ret_std1, ret_custom1);
	assert_eq(ret_std2, ret_custom2);
}

// Test avec le buffer déjà plein.
void	test_ft_strlcat_buffer_full(void)
{
	char	dest_std[6];
	char	dest_custom[6];
	const char	src[] = "Overflow";
	size_t	size;
	size_t	ret_std;
	size_t	ret_custom;

	size = 5;
	memset(dest_std, 'G', 4);
	dest_std[4] = '\0';
	memset(dest_custom, 'G', 4);
	dest_custom[4] = '\0';
	ret_std = strlcat(dest_std, src, size);
	ret_custom = ft_strlcat(dest_custom, src, size);
	asser_cmp_buf(dest_std, dest_custom, 5);
	assert_eq(ret_std, ret_custom);
}

int	main(void)
{
	run_test(test_ft_strlcat_basic, "ft_strlcat_basic");
	run_test(test_ft_strlcat_zero_size, "ft_strlcat_zero_size");
	run_test(test_ft_strlcat_full_concat, "ft_strlcat_full_concat");
	run_test(test_ft_strlcat_truncate, "ft_strlcat_truncate");
	run_test(test_ft_strlcat_large_size, "ft_strlcat_large_size");
	run_test(test_ft_strlcat_multiple_calls, "ft_strlcat_multiple_calls");
	run_test(test_ft_strlcat_buffer_full, "ft_strlcat_buffer_full");
	return (0);
}
 */