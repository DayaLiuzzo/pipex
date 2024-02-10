/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:10:06 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/10 13:05:02 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void init_struct(t_rome *rome)
{
    rome->command = NULL;
    rome->commandpath = NULL;
    rome->paths = NULL;
    rome->exe = NULL;
    rome->sub = NULL;
    rome->i = 0;
    rome->j = 0;
    rome->f = -1;
    rome->id = 2;
    rome->f1 = -1;
    rome->f2 = -1;
}