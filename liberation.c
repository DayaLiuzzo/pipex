/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:23:36 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/12 12:51:58 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_path(t_rome *rome)
{
	int	i;

	if (rome->paths)
	{
		i = 0;
		while (rome->paths[i])
		{
			free(rome->paths[i]);
			i++;
		}
		free(rome->paths);
	}
}

void	free_command(t_rome *rome)
{
	int	i;

	if (rome->command)
	{
		i = 0;
		while (rome->command[i])
		{
			free(rome->command[i]);
			i++;
		}
		free(rome->command);
	}
}

int	path_error2(t_rome *rome)
{
	free_path(rome);
	free_command(rome);
	if (rome->commandpath)
	{
		free(rome->commandpath);
	}
	exit(1);
}

int	path_error(char *msg, t_rome *rome)
{
	if (msg)
		ft_printf("%s\n", msg);
	free_path(rome);
	free_command(rome);
	if (rome->commandpath)
	{
		free(rome->commandpath);
	}
	exit(1);
}

int	liberation(char *msg, t_rome *rome)
{
	if (msg)
		ft_printf("%s\n", msg);
	free_path(rome);
	free_command(rome);
	if (rome->commandpath)
		free(rome->commandpath);
	exit(1);
}
