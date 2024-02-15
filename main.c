/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:51:03 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/15 18:25:01 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_rome	rome;
	int fd[2];
	int pid1;
	int pid2;
	
	init_struct(&rome);
	check_args(ac, av, env, &rome);
	if (pipe(fd) < 0)
		path_error("Pipe Error", &rome);
	pid1 = fork();
	if (pid1 < 0)
		path_error("Fork Error", &rome);
	if(pid1 == 0)
	{
		dup2(rome.f1, STDIN_FILENO);
		close(rome.f1);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		ft_exec(&rome, av[2], env);
	}
	pid2 = fork();
	if (pid2 < 0)
		path_error("Fork Error", &rome);
	if (pid2 == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		dup2(rome.f2, STDOUT_FILENO);
		close(rome.f2);
		ft_exec(&rome, av[3], env);
	}
	// waitpid(pid1, NULL, 1);
	// waitpid(pid2, NULL, 1);
	return (0);
}


// par defaut, 