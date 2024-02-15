/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:11:45 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/15 15:32:28 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmpp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (s1 || s2)
	{
		while (s1 && s1[i] && s2 && s2[i] && i < n)
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	add_pipe(char *av, char **env, t_rome *rome, int i)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (pid == 0 && i != 0)
	{
		perror("Child");
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		if (ft_exec(rome, av, env) == 1)
			exit(0);
	}
	if (pid == 0 && i == 0)
	{
		dup2(rome->f2, STDOUT_FILENO);
		close(rome->f1);
		close(rome->f2);
		ft_exec(rome, av, env);
	}
	return (0);
}

void	ft_here_doc(char **end)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (pid == 0)
		fill_pipe(end, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	waitpid(pid, NULL, 0);
}

void	fill_pipe(char **end, int fd[2])
{
	char	*cline;

	close(fd[0]);
	while (1)
	{
		cline = get_next_line(0);
		if (ft_strncmpp(end[2], cline, ft_strlen(end[2])) == 1)
		{
			free(cline);
			exit(0);
		}
		ft_putstr_fd(cline, fd[1]);
		free(cline);
	}
	return ;
}
