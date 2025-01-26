/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:55:37 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/26 13:58:39 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_arguments(int argc, char **argv, t_pipex *data)
{
	if (argc != 5)
	{
		perror("Usage: ./pipex file1 \"cmd1\" \"cmd2\" file2");
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) != 0 && access(argv[4], W_OK) != 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	data->infile = argv[1];
	data->cmd1 = ft_split(argv[2], ' ');
	data->cmd2 = ft_split(argv[3], ' ');
	data->outfile = argv[4];
	if (data->cmd1 == NULL || data->cmd2 == NULL)
	{
		perror("Error allocating memory");
		clear_data(data);
		exit(EXIT_FAILURE);
	}
}
