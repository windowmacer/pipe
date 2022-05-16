/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:42:15 by pbronn            #+#    #+#             */
/*   Updated: 2022/03/09 18:19:45 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_gnl
{
	char			*stl;
	char			*str;
	int				f;
	ssize_t			gg;
}	t_gnl;

char			*get_next_line(int fd);
char			*ft_freejoin(char	*s1, char	*s2);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *str1, const char *str2, size_t num);
char			*ft_strchr(const char *str, int ch);
char			*ft_strndup(char *s1, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *str);
char			**ft_split(char const *s, char c);
char			*ft_strnstr(const char *source, const char *find, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
int				openfile(char *file, int mode);
char			**ft_path(char **env);
char			*ft_dir(char **env, char *cmd);
void			cmd2(char *command, char **env);
void			cmd1(char *command, char **env, int infile_fd);
int				ft_heredoc(char **av);

#endif
