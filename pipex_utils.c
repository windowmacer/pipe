/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:41:49 by pbronn            #+#    #+#             */
/*   Updated: 2022/02/18 20:24:14 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	openfile(char *file, int mode)
{
	if (mode == 0)
	{
		if (access(file, F_OK))
		{
			write(2, "File not found\n", 15);
			return (0);
		}
		return (open(file, O_RDONLY));
	}
	else
		return (open(file, O_CREAT | O_RDWR | O_TRUNC, 0644));
}

char	**ft_path(char **env)
{
	char	**path_split;
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5) != NULL)
		{
			path = ft_strdup(&env[i][5]);
			break ;
		}
		i++;
	}
	path_split = ft_split(path, ':');
	free(path);
	return (path_split);
}

char	*ft_dir(char **env, char *cmd)
{
	int		i;
	char	*full;
	char	*dir;
	char	**path_split;

	i = 0;
	path_split = ft_path(env);
	while (path_split[i])
	{
		dir = ft_strjoin(path_split[i], "/");
		full = ft_strjoin(dir, cmd);
		free(dir);
		free(path_split[i]);
		if (access(full, F_OK) == 0)
		{
			free(path_split);
			return (full);
		}
		else
			free(full);
		i++;
	}
	free(path_split);
	return (NULL);
}
