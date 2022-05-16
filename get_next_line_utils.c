/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:20:09 by pbronn            #+#    #+#             */
/*   Updated: 2022/03/09 18:58:56 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strchr(const char *str, int ch)
{
	char	*s;
	char	c;

	if (!str)
		return (NULL);
	c = (char)ch;
	s = (char *)str;
	while (*s != c)
	{
		if (*s == '\0')
		{
			return (NULL);
		}
		s++;
	}
	return (s);
}

char	*ft_strndup(char *s1, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc(sizeof(char) * (n + 1));
	if (!ptr)
		return (NULL);
	while (i < n)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	*ft_freejoin(char	*s1, char	*s2)
{
	char	*str;

	if (!s1)
		s1 = ft_strndup("", 0);
	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}
