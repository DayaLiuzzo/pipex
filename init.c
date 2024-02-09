/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:10:06 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/09 20:39:42 by dliuzzo          ###   ########.fr       */
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
    rome->id = 1;
}