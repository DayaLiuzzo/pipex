/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:00:49 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/08 17:30:34 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int exec_command(t_rome **rome,char const **env)
{
    
    if (execve(rome->commandpath, rome->command, NULL) == -1)
    {
        path_error("Exec Failure", rome);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void *get_command_path(t_rome **rome)
{
    int i;
    int f;

    i = 0;
    f = -1;
    if(rome->command && rome->paths && rome->command[0])
    {
        while(rome->paths[i] && f == -1)
        {
            rome->paths[i] = ft_strjoin(rome->paths[i], "/");
            if (!rome->paths[i])
                path_error("Alloc Error", rome);
            rome->paths[i] = ft_strjoin(rome->paths[i], rome->command[0]);
            if (!rome->paths[i])
                path_error("Alloc Error", rome);
            if (access(rome->paths[i], X_OK) == 0)
                f = i;
            i++;
        }
    }
    if (f = -1)
        path_error("Can't Find Path", rome);
    rome->commandpath = ft_strdup(rome->paths[f]);
    if (!rome->commandpath)
        path_error("Alloc Error", rome);
}

void **get_paths(t_rome **rome, char **env)
{
    int i;
    int j;
    
    i = 0;
    j = -1;
    while(env[i])
    {
        if (strncmp("PATH=", env[i], 4))
        {
            j = i;
            break;
        }
        i++;
    }
    if(j != -1)
    {
        rome->paths = ft_split(env[j], ':');
        if (!rome->paths)
            path_error("Error Alloc", rome);
    }
    else 
        path_error("Cant find Path", rome);  
}

void **get_command(t_rome **rome, char *av)
{
    
    rome->command = ft_split(av, ' ');
    if(!rome->command)
        ft_error("Error Alloc", rome);
}