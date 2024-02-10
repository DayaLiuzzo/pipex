/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:51:03 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/10 14:09:41 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int    ac, char **av, char **env)
{
    t_rome rome;

    init_struct(&rome);
    check_args(ac, av, env, &rome);
    if(rome.id == 3)
        ft_here_doc(av[2]);
    else
        dup2(rome.f1, STDIN_FILENO);
    while (rome.id < ac - 2)
    
    
    ft_exec(&rome, av[ac - 2], env);
    liberation("finito pipo", &rome);
    return(0);
}

// PATH il faut fouiller dans chaque chemin chaque commande les chemins sont separes par 2 points:
