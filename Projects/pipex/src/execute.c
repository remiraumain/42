/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:03:03 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/26 14:18:29 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// dup2(pipe_fd[0], STDIN_FILENO); 
// Redirige l'entrée standard vers le pipe (read end)
// dup2(fd_out, STDOUT_FILENO); 
// Redirige la sortie standard vers le fichier de sortie

void	execute_child1(int pipe_fd[2], char **envp, t_pipex *data)
{
	int	fd_in;

	fd_in = open(data->infile, O_RDONLY);
	if (fd_in < 0)
	{
		perror("Error opening input file");
		clear_data(data);
		exit(EXIT_FAILURE);
	}
	dup2(fd_in, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(fd_in);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execve(get_command_path(data->cmd1[0], envp), data->cmd1, envp);
	perror("Exec failed");
	clear_data(data);
	exit(EXIT_FAILURE);
}

void	execute_child2(int pipe_fd[2], char **envp, t_pipex *data)
{
	int	fd_out;

	fd_out = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out < 0)
	{
		perror("Error opening output file");
		clear_data(data);
		exit(EXIT_FAILURE);
	}
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execve(get_command_path(data->cmd2[0], envp), data->cmd2, envp);
	perror("Exec failed");
	clear_data(data);
	exit(EXIT_FAILURE);
}
