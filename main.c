/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:51:03 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/08 17:18:37 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int    ac, char **av, char **env)
{
    t_rome *rome;
    
    rome = init_struct();
    check_args(ac, av, env, &rome);
    printf("%i, %s",ac,  av[0]);
    return(0);
}

// PATH il faut fouiller dans chaque chemin chaque commande les chemins sont separes par 2 points:
