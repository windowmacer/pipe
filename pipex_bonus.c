/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:50:09 by pbronn            #+#    #+#             */
/*   Updated: 2022/03/09 19:19:44 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	opfile(char *filename, int mode, int h)
{
	if (mode == 0)
	{
		if (access(filename, F_OK))
		{
			write(2, "File not found\n", 15);
			return (0);
		}
		return (open(filename, O_RDONLY));
	}
	else if (mode == 1 && h == 1)
		return (open(filename, O_CREAT | O_RDWR | O_APPEND, 0644));
	else
		return (open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644));
}

void	second_cmd(char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	path = ft_dir(env, args[0]);
	execve(path, args, env);
	write(2, "Сommand not found\n", 19);
	sleep(120);
	exit(7);
}

void	first_cmd(char *cmd, char **env, int fdin)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		if (fdin == 0)
			exit(1);
		else
			second_cmd(cmd, env);
	}
}

int	ft_fd_in(int ac, char **av, int *h)
{
	int	fdin;

	if ((!ft_strncmp(av[1], "here_doc", 8)) && ac >= 6)
	{
		fdin = ft_heredoc(av);
		*h = 1;
	}
	else
	{
		*h = 0;
		fdin = opfile(av[1], 0, 0);
	}
	return (fdin);
}

int	main(int ac, char **av, char **env)
{
	int	fdin;
	int	fdout;
	int	i;
	int	h;

	h = 0;
	i = 3;
	if (ac >= 5)
	{
		fdin = ft_fd_in(ac, av, &h);
		i += h;
		fdout = opfile(av[ac - 1], 1, h);
		dup2(fdin, 0);
		dup2(fdout, 1);
		first_cmd(av[(h + 2)], env, fdin);
		while (i < ac - 2)
			first_cmd(av[i++], env, 1);
		if (h)
			unlink("temp.txt");
		second_cmd(av[i], env);
	}
	else
		write(2, "Invalid number of arguments.\n", 29);
	return (1);
}
