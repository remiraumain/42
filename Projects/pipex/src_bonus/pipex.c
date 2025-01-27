/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:01:16 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/27 09:22:40 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	create_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
	{
		perror("Pipe failed");
		return (-1);
	}
	return (0);
}

void	close_and_wait(int pipe_fd[2])
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(NULL);
	wait(NULL);
}

void	pipex(t_pipex *data, char **env)
{
	int	i;
	int	pipe_fd[2];
	int	prev_fd;
	int	pid;

	prev_fd = open(data->infile, O_RDONLY);
	if (prev_fd == -1)
	{
		perror("Error opening infile");
		clear_data(data);
		exit(EXIT_FAILURE);
	}
	i = 2;
	while (i < data->argc - 2)
	{
		pipe(pipe_fd);
		pid = fork();
		if (pid == 0)
		{
			close(pipe_fd[0]);

		}
		i++;
	}
}
