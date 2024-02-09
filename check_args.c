/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:01:19 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/09 21:14:18 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void check_args(int ac, char **av, char **env, t_rome *rome)
{
    int fd;
    
    if(ac <= 4)
        liberation("des arguments ouuu", rome);
    if(!env[0])
        liberation("ou est l environnement mv ?", rome);
    if(ft_strncmpp(av[1], "here_doc", 9 ))
        rome->id = 3;
    if(rome->id == 1)
    {   
        fd = open(av[rome->id], O_RDONLY);
        if(fd == -1)
            liberation("WRONG FILE", rome);
        close(fd);
        
    }
    fd = open(av[ac-1], O_WRONLY);
    if (fd == -1)
        liberation("WRONG FILE", rome);
    close(fd);
}