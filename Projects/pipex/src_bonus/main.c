/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:51:05 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/27 09:07:43 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	int		pipe_fd[2];
	int		prev_fd[];
	pid_t	pid1;
	pid_t	pid2;

	parse_arguments(argc, argv, &data);
	if (create_pipe(pipe_fd) == -1)
	{
		clear_data(&data);
		exit(EXIT_FAILURE);
	}
	while ()
	{
		pid = fork();
		if (pid == -1)
		{
			printf("Error using strerror: %s\n", strerror(errno));
			clear_data(&data);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
			execute_child1(pipe_fd, envp, &data);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		printf("Error using strerror: %s\n", strerror(errno));
		clear_data(&data);
		exit(EXIT_FAILURE);
	}
	if (pid1 == 0)
		execute_child1(pipe_fd, envp, &data);
	pid2 = fork();
	if (pid2 == -1)
	{
		printf("Error using strerror: %s\n", strerror(errno));
		clear_data(&data);
		exit(EXIT_FAILURE);
	}
	if (pid2 == 0)
		execute_child2(pipe_fd, envp, &data);
	close_and_wait(pipe_fd);
	clear_data(&data);
	return (0);
}
