/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 09:45:01 by pbronn            #+#    #+#             */
/*   Updated: 2022/02/17 16:34:29 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	ft_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *source, const char *find, size_t n)
{
	char	*ch;
	size_t	len;
	size_t	j;
	size_t	i;

	ch = (char *)source;
	len = ft_len(find);
	if (!len)
		return (ch);
	if (ft_len(source) < len || n < len)
		return (0);
	i = 0;
	while (ch[i] && i <= n - len)
	{
		j = 0;
		while (find[j] && find[j] == ch[i + j])
			j++;
		if (j == len)
			return (&ch[i]);
		i++;
	}
	return (0);
}
