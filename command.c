/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:00:49 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/13 17:59:20 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_exec(t_rome *rome, char *av, char **env)
{
	get_command(rome, av);
	if(rome->command[0] && rome->command[0][0] != '\0')
	{
		if(access(rome->command[0], F_OK | X_OK ) != 0 ||
		 ft_strchr(rome->command[0], '/') == NULL)
		{
			get_paths(rome, env);
			get_command_path(rome);
		}
		else 
		rome->commandpath = rome->command[0];
		exec_command(rome, env);
	}
	path_error(rome->commandpath, rome);
	return 1;
}

int	exec_command(t_rome *rome, char **env)
{
	int	i;

	i = 0;
	if (execve(rome->commandpath, rome->command, env) == -1)
	{
		path_error("Exec Failure", rome);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	get_command_path(t_rome *rome)
{
	while (rome->paths[rome->i] && rome->f == -1)
	{
		rome->sub = ft_strjoin(rome->paths[rome->i], "/");
		if (!rome->sub)
			path_error("Alloc Error", rome);
		rome->exe = ft_strjoin(rome->sub, rome->command[0]);
		if (!rome->exe)
			path_error("Alloc Error", rome);
		free(rome->sub);
		if (access(rome->exe, F_OK | X_OK) == 0)
		{
			rome->f = 1;
			rome->commandpath = ft_strdup(rome->exe);
			if (!rome->commandpath)
				path_error("Alloc Error", rome);
			free(rome->exe);
			break ;
		}
		rome->i++;
		free(rome->exe);
	}
	if (rome->f == -1)
		path_error("Command Not Found", rome);
}

void	get_paths(t_rome *rome, char **env)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (env[i])
	{
		if (ft_strncmpp("PATH=", env[i], 4) == 1)
		{
			j = i;
			break ;
		}
		i++;
	}
	if (j != -1)
	{
		rome->paths = ft_split(env[j], ':');
		if (!rome->paths)
			path_error("Error Alloc", rome);
	}
	else
		path_error2(rome);
}

void	get_command(t_rome *rome, char *av)
{
	if(av)
	{
		rome->command = ft_split(av, ' ');
		if (!rome->command)
			path_error("Error Alloc", rome);
	}
}
