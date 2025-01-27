/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:55:37 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/27 09:20:43 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	parse_arguments(int argc, char **argv, t_pipex *data)
{
	int i;

	if (argc < 5)
	{
		perror("Usage: ./pipex file1 \"cmd1\" \"cmd2\" file2");
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) != 0 && access(argv[argc - 1], W_OK) != 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	data->infile = argv[1];
	data->outfile = argv[argc - 1];
	data->argc = argc;
	data->cmds = malloc(sizeof(char ***));
	if (data->cmds == NULL)
	{
		perror("Error allocating memory");
		clear_data(data);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < argc - 2)
	{
		data->cmds[i] = ft_split(argv[2], ' ');
		if (data->cmds[i] == NULL)
		{
			perror("Error allocating memory");
			clear_data(data);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
