/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:01:19 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/10 17:16:40 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void check_args(int ac, char **av, char **env, t_rome *rome)
{
    if(ac <= 4)
        liberation("des arguments ouuu", rome);
    if(!env[0])
        liberation("ou est l environnement mv ?", rome);
    if(ft_strncmpp(av[1], "here_doc", 9 ))
    {
        rome->id = 3;
        rome->f2 = open(av[ac-1], O_WRONLY);
    }
    if(rome->id == 2)
    {   
        rome->f1 = open(av[1], O_RDONLY);
        rome->f2 = open(av[ac-1], O_WRONLY);
    }
}

void ft_here_doc(char **end)
{
    int fd[2];
    int pid;
    
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

void fill_pipe(char **end, int fd[2])
{
    char *cline;
    
    //close reading end of pipe cos we read from stdin
    close(fd[0]);
    while(1)
    {
        cline = get_next_line(0);
        if(ft_strncmpp(cline, end[2], ft_strlen(end[2])) == 0)
        {
            free(cline);
            exit(0);
        }
        ft_putstr_fd(cline, fd[1]);
        free(cline);
    }
    return;
    
}