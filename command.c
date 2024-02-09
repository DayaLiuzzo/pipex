/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:00:49 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/09 17:51:36 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int exec_command(t_rome *rome,char const **env)
{
    int i;
    i = 0;
    
    if (env[i])
    printf("%s", env[i]);
    
    if (execve(rome->commandpath, rome->command, NULL) == -1)
    {
        path_error("Exec Failure", rome);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void get_command_path(t_rome *rome)
{
    if(rome->command && rome->paths && rome->command[0])
    {
        while(rome->paths[rome->i] && rome->f == -1)
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
                free(rome->exe);
                break ;
            }
            rome->i++;
            free(rome->exe);
        }
    }
    if (rome->f == -1)
        path_error("Can't Find Path", rome);
    rome->commandpath = ft_strdup(rome->paths[rome->i]);
    if (!rome->commandpath)
        path_error("Alloc Error", rome);
}

void get_paths(t_rome *rome, char **env)
{
    int i;
    int j;
    
    i = 0;
    j = -1;
    while(env[i])
    {
        if (ft_strncmpp("PATH=", env[i], 4) == 1)
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

void get_command(t_rome *rome, char *av)
{
    
    rome->command = ft_split(av, ' ');
    if(!rome->command)
        path_error("Error Alloc", rome);
}