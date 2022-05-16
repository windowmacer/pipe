/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:50:18 by pbronn            #+#    #+#             */
/*   Updated: 2022/03/07 16:55:59 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_heredoc(char **av)
{
	int		in;
	int		fd;
	char	*line;

	if (!ft_strncmp(av[1], "here_doc", 8))
		fd = open("temp.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (1)
	{
		write(1, "pipe heredoc>", 13);
		line = (get_next_line(0));
		if (!ft_strncmp(av[2], line, ft_strlen(av[2])))
			break ;
		write(fd, line, ft_strlen(line));
		free(line);
	}
	close(fd);
	in = open("temp.txt", O_RDONLY);
	return (in);
}
