/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:01:19 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/09 20:22:48 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void check_args(int ac, char **av, char **env, t_rome *rome)
{
    // int i;
    
    if(ac <= 4)
        liberation("des arguments ouuu", rome);
    if(!env[0])
        liberation("ou est l environnement mv ?", rome);
    else
    printf("%i ac, %s av, %s env\n\n", ac, av[0], env[0]);
    
}