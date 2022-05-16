/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:19:34 by pbronn            #+#    #+#             */
/*   Updated: 2022/03/09 17:47:39 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdlib.h>

static char	*null_storage(char	**stl, int	*f, int x)
{
	char	*p;
	char	*s;

	*f = x;
	if (!*stl)
		return (ft_strndup("", 0));
	p = ft_strchr(*stl, '\n');
	if (!p)
	{
		s = *stl;
		return (s);
	}
	s = ft_strndup(*stl, ((p - *stl) + 1));
	if (!s)
		return (NULL);
	free(*stl);
	*stl = NULL;
	return (s);
}

static char	*storage(char	**stl)
{
	char	*p;
	char	*temp;
	char	*s;

	if (!*stl)
		return (ft_strndup("", 0));
	p = ft_strchr(*stl, '\n');
	if (!p)
	{
		s = *stl;
		return (s);
	}
	s = ft_strndup(*stl, ((p - *stl) + 1));
	if (!s)
		return (NULL);
	temp = ft_strndup(p + 1, ft_strlen(p + 1));
	free(*stl);
	if (!temp)
	{
		free(s);
		return (NULL);
	}
	*stl = temp;
	return (s);
}

static int	check_line(char *stl)
{
	char	*p;

	p = ft_strchr(stl, '\n');
	if (stl && (ft_strchr(stl, '\n')) && (!(*(p++))))
		return (-1);
	if (stl && (ft_strchr(stl, '\n')) && ((*(p))))
		return (1);
	return (0);
}

char	*ft_gnl(int fd, t_gnl	*st, char	*buf)
{
	static char		*stl;
	static int		f;

	if (f > 0 && (check_line(stl) < 0))
		return (null_storage(&stl, &f, 1));
	else if (f > 0 && (check_line(stl) > 0))
		return (storage(&stl));
	while (st->gg)
	{
		st->gg = read(fd, buf, 1);
		if (!st->gg)
			break ;
		buf[st->gg] = '\0';
		f = 1;
		stl = ft_freejoin(stl, buf);
		if (ft_strchr(buf, '\n'))
			st->gg = 0;
		if (check_line(stl) < 0)
			return (null_storage(&stl, &f, 1));
		else if (check_line(stl) > 0)
			return (storage(&stl));
	}
	if ((f > 0))
		return (null_storage(&stl, &f, -1));
	return (NULL);
}

char	*get_next_line(int fd)
{
	t_gnl			st;
	char			buf[2];

	if (read(fd, buf, 0) == -1)
		return (NULL);
	st.gg = 1;
	return (ft_gnl(fd, &st, buf));
}
