/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:03:03 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/27 09:26:22 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
// dup2(pipe_fd[0], STDIN_FILENO); 
// Redirige l'entrée standard vers le pipe (read end)
// dup2(fd_out, STDOUT_FILENO); 
// Redirige la sortie standard vers le fichier de sortie

void	execute_cmd(char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	path = get_command_path(args[0], env);
	if (!path)
	{
		perror("Command not found");
		exit(EXIT_FAILURE);
	}
	execve(path, args, env);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

void	execute_first_child(int pipe_fd[2], char **envp, t_pipex *data)
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

void	execute_last_child(int pipe_fd[2], char **envp, t_pipex *data)
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

void	execute_mid_child(char *cmd, int input_fd, int output_fd, char **env)
{
	dup2(input_fd, STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	exec_cmd(cmd, env);
}