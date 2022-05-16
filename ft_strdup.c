/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 09:39:16 by pbronn            #+#    #+#             */
/*   Updated: 2022/02/17 16:34:10 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	ft_ln(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*ch;
	int		i;

	i = 0;
	ch = malloc(ft_ln(str) + 1);
	if (ch == NULL)
		return (NULL);
	while (str[i])
	{
		ch[i] = str[i];
		i++;
	}
	ch[i] = '\0';
	return (ch);
}
