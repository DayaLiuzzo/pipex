/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:51:03 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/08 18:25:55 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int    ac, char **av, char **env)
{
    t_rome rome;
    int i;

    i = 0;
    
    init_struct(&rome);
    check_args(ac, av, env, &rome);
    get_command(&rome, av[1]);
    get_paths(&rome, env);
    while (rome.paths && rome.paths[i])
    {
        printf("%s\n", rome.paths[i]);
        i++;
    }
    get_command_path(&rome);
    printf("%i, %s",ac,  av[0]);
    liberation("finito pipo", &rome);
    return(0);
}

// PATH il faut fouiller dans chaque chemin chaque commande les chemins sont separes par 2 points:
