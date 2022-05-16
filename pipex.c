/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:41:42 by pbronn            #+#    #+#             */
/*   Updated: 2022/03/09 19:09:33 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd2(char *command, char **env)
{
	char	**args;
	char	*path;
	int		i;

	i = 0;
	args = ft_split(command, ' ');
	path = ft_dir(env, args[0]);
	execve(path, args, env);
	write(2, "Command not found\n", 19);
	exit(2);
}

void	cmd1(char *command, char **env, int infile_fd)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) < 0)
		return (perror("Pipe"));
	pid = fork();
	if (pid < 0)
		return (perror("Fork"));
	if (!pid)
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		if (infile_fd == 0)
			exit(1);
		else
			cmd2(command, env);
	}
	close(pipefd[1]);
	dup2(pipefd[0], 0);
}

int	main(int ac, char **av, char **env)
{
	int	infile_fd;
	int	outfile_fd;

	if (ac == 5)
	{
		infile_fd = openfile(av[1], 0);
		outfile_fd = openfile(av[4], 1);
		dup2(infile_fd, 0);
		dup2(outfile_fd, 1);
		cmd1(av[2], env, infile_fd);
		cmd2(av[3], env);
		wait(NULL);
	}
	else
		write(2, "Error", 5);
	return (1);
}
