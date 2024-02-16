/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:43:00 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/16 13:41:31 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../libft/includes/libft.h"
# include "../libft/includes/printf.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_rome
{
	char	**paths;
	char	**command;
	char	*commandpath;
	char	*sub;
	char	*exe;
	int		i;
	int		j;
	int		f;
	int		id;
	int		f1;
	int		f2;

}			t_rome;

void		get_command(t_rome *rome, char *av);
void		init_struct(t_rome *rome);
void		check_args(int ac, char **av, char **env, t_rome *rome);
void		get_paths(t_rome *rome, char **env);
void		get_command_path(t_rome *rome);
void		fill_pipe(char **end, int fd[2]);
void		ft_here_doc(char **end);
void		free_path(t_rome *rome);
int			main(int ac, char **av, char **env);
int			liberation(char *msg, t_rome *rome);
int			path_error(char *msg, t_rome *rome);
int			path_error2(t_rome *rome);
int			ft_strncmpp(char *s1, char *s2, int n);
int			exec_command(t_rome *rome, char **env);
int			ft_exec(t_rome *rome, char *av, char **env);
int			add_pipe(char *av, char **env, t_rome *rome, int i);
int			ft_strlen2(const char *str);
int			find_the_n(char *storage);
char		*get_next_line(int fd);
char		*ft_strjoin2(char *s1, char *s2);
#endif
