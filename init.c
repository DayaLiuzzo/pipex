/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:10:06 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/08 17:37:28 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

t_rome *init_struct(void)
{
    t_rome *rome;
    
    rome = (t_rome *)malloc(sizeof(t_rome));
    if (!rome)
        exit(1);
    ft_bzero(rome, sizeof(t_rome));
    return (rome);
}

t_rome *init_struct(void)
{
    t_rome *rome;
    
    rome = (t_rome *)malloc(sizeof(t_rome));
    if (!rome)
        exit(1);
    ft_bzero(rome, sizeof(t_rome));
    return (rome);
}