/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:31:10 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/16 15:51:22 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_childlabor2(t_rome *rome, char **av, char **env)
{
	dup2(rome->fd[0], STDIN_FILENO);
	dup2(rome->f2, STDOUT_FILENO);
	ft_closefd(rome);
	return (ft_exec(rome, av[3], env));
}

int	ft_childlabor1(t_rome *rome, char **av, char **env)
{
	dup2(rome->f1, STDIN_FILENO);
	dup2(rome->fd[1], STDOUT_FILENO);
	ft_closefd(rome);
	return (ft_exec(rome, av[2], env));
}

void	ft_closefd(t_rome *rome)
{
	close(rome->fd[0]);
	close(rome->fd[1]);
	close(rome->f1);
	close(rome->f2);
}
