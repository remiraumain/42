/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:49:05 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/22 23:19:10 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_filename_valid(char *filename)
{
	unsigned int	len;

	len = ft_strlen(filename);
	return (!ft_strncmp(filename + (len - 4), ".ber", 4));
}

int	parse_arg(char *arg)
{
	if (!arg)
		return (error_int("No map specified"));
	if (!is_filename_valid(arg))
		return (error_int("Invalid file extension"));
	return (0);
}
