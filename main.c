/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:51:03 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/09 19:53:40 by dliuzzo          ###   ########.fr       */
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
    ft_exec(&rome, av, env);
    liberation("finito pipo", &rome);
    return(0);
}

// PATH il faut fouiller dans chaque chemin chaque commande les chemins sont separes par 2 points:
