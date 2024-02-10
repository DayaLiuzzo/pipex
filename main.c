/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:51:03 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/10 16:03:40 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int    ac, char **av, char **env)
{
    t_rome rome;

    init_struct(&rome);
    check_args(ac, av, env, &rome);
    if(rome.id == 3)
        ft_here_doc(av);
    else
        dup2(rome.f1, STDIN_FILENO);
    while (rome.id < ac - 2)
        add_pipe(av[rome.id++], env, &rome);
    dup2(rome.f2, STDOUT_FILENO);
    close(rome.f1);
    close(rome.f2);
    ft_exec(&rome, av[ac - 2], env);
    liberation("finito pipo", &rome);
    return(0);
}

int add_pipe(char *av, char **env, t_rome *rome)
{
    int fd[2];
    int pid;
    
    if (pipe(fd) == -1)
        liberation("pipe ERROR", rome);
    pid = fork();
    if (pid == -1)
        liberation("Fork ERROR", rome);
    if (pid == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        if (ft_exec(rome, av, env) == 1)
            liberation("command failure", rome);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
    }
    return(0);
}

// PATH il faut fouiller dans chaque chemin chaque commande les chemins sont separes par 2 points:
