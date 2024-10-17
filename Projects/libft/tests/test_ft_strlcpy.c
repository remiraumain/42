/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:28:25 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 14:28:25 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Test de base pour ft_strlcpy.
void	test_ft_strlcpy_basic(void)
{
	char	buffer_std[11];
	char	buffer_custom[11];
	const char	src[] = "Hello";
	size_t	n;
	size_t	ret_std;
	size_t	ret_custom;

	n = 6;
	memset(buffer_std, 'A', 10);
	buffer_std[10] = '\0';
	memset(buffer_custom, 'A', 10);
	buffer_custom[10] = '\0';
	ret_std = strlcpy(buffer_std, src, n);
	ret_custom = ft_strlcpy(buffer_custom, src, n);
	asser_cmp_buf(buffer_std, buffer_custom, 10);
	assert_eq(ret_std, ret_custom);
}

// Test avec n = 0.
void	test_ft_strlcpy_zero_size(void)
{
	char	buffer_std[11];
	char	buffer_custom[11];
	const char	src[] = "World";
	size_t	n;
	size_t	ret_std;
	size_t	ret_custom;

	n = 0;
	memset(buffer_std, 'B', 10);
	buffer_std[10] = '\0';
	memset(buffer_custom, 'B', 10);
	buffer_custom[10] = '\0';
	ret_std = strlcpy(buffer_std, src, n);
	ret_custom = ft_strlcpy(buffer_custom, src, n);
	asser_cmp_buf(buffer_std, buffer_custom, 10);
	assert_eq(ret_std, ret_custom);
}

// Test de copie complète du buffer.
void	test_ft_strlcpy_full_size(void)
{
	char	buffer_std[16];
	char	buffer_custom[16];
	const char	src[] = "CompleteCopy!";
	size_t	n;
	size_t	ret_std;
	size_t	ret_custom;

	n = 16;
	memset(buffer_std, 'C', 15);
	buffer_std[15] = '\0';
	memset(buffer_custom, 'C', 15);
	buffer_custom[15] = '\0';
	ret_std = strlcpy(buffer_std, src, n);
	ret_custom = ft_strlcpy(buffer_custom, src, n);
	asser_cmp_buf(buffer_std, buffer_custom, 16);
	assert_eq(ret_std, ret_custom);
}

// Test avec une taille grande (1024 octets).
void	test_ft_strlcpy_large_size(void)
{
	size_t	n;
	char	*buffer_std;
	char	*buffer_custom;
	char	*src;
	size_t	ret_std;
	size_t	ret_custom;

	n = 1024;
	buffer_std = malloc(n + 1);
	buffer_custom = malloc(n + 1);
	src = malloc(n + 1);
	if (!buffer_std || !buffer_custom || !src)
	{
		assert_eq(1, 0);
		return ;
	}
	memset(buffer_std, 'D', n);
	buffer_std[n] = '\0';
	memset(buffer_custom, 'D', n);
	buffer_custom[n] = '\0';
	memset(src, 'E', n);
	src[n] = '\0';
	ret_std = strlcpy(buffer_std, src, n + 1);
	ret_custom = ft_strlcpy(buffer_custom, src, n + 1);
	asser_cmp_buf(buffer_std, buffer_custom, n + 1);
	assert_eq(ret_std, ret_custom);
	free(buffer_std);
	free(buffer_custom);
	free(src);
}

// Test multiple appels de ft_strlcpy sur le même buffer.
void	test_ft_strlcpy_multiple_calls(void)
{
	char	buffer_std[21];
	char	buffer_custom[21];
	const char	src1[] = "FirstCopy";
	const char	src2[] = "SecondCopy";
	size_t	n1;
	size_t	n2;
	size_t	ret_std1;
	size_t	ret_custom1;
	size_t	ret_std2;
	size_t	ret_custom2;

	n1 = 10;
	n2 = 11;
	memset(buffer_std, 'F', 20);
	buffer_std[20] = '\0';
	memset(buffer_custom, 'F', 20);
	buffer_custom[20] = '\0';
	ret_std1 = strlcpy(buffer_std, src1, n1 + 1);
	ret_custom1 = ft_strlcpy(buffer_custom, src1, n1 + 1);
	ret_std2 = strlcpy(buffer_std + n1, src2, n2 + 1);
	ret_custom2 = ft_strlcpy(buffer_custom + n1, src2, n2 + 1);
	asser_cmp_buf(buffer_std, buffer_custom, 20);
	assert_eq(ret_std1, ret_custom1);
	assert_eq(ret_std2, ret_custom2);
}

// Test avec des buffers contenant déjà des zéros.
void	test_ft_strlcpy_already_zero(void)
{
	char	buffer_std[11];
	char	buffer_custom[11];
	const char	src[] = "ZeroCopy";
	size_t	n;
	size_t	ret_std;
	size_t	ret_custom;

	n = 10;
	memset(buffer_std, 0, 10);
	buffer_std[10] = '\0';
	memset(buffer_custom, 0, 10);
	buffer_custom[10] = '\0';
	ret_std = strlcpy(buffer_std, src, n + 1);
	ret_custom = ft_strlcpy(buffer_custom, src, n + 1);
	asser_cmp_buf(buffer_std, buffer_custom, 11);
	assert_eq(ret_std, ret_custom);
}

int	main(void)
{
	run_test(test_ft_strlcpy_basic, "ft_strlcpy_basic");
	run_test(test_ft_strlcpy_zero_size, "ft_strlcpy_zero_size");
	run_test(test_ft_strlcpy_full_size, "ft_strlcpy_full_size");
	run_test(test_ft_strlcpy_large_size, "ft_strlcpy_large_size");
	run_test(test_ft_strlcpy_multiple_calls, "ft_strlcpy_multiple_calls");
	run_test(test_ft_strlcpy_already_zero, "ft_strlcpy_already_zero");
	return (0);
} */