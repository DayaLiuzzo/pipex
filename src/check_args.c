/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:01:19 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/16 15:36:25 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int ac, char **av, char **env, t_rome *rome)
{
	if (ac != 5)
		liberation("des arguments ouuu", rome);
	if (!env[0])
		liberation("ou est l environnement mv ?", rome);
	rome->f1 = open(av[1], O_RDONLY, 0777);
	if (rome->f1 < 0)
		liberation("ERROR", rome);
	rome->f2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (rome->f1 < 0)
		liberation("ERROR", rome);
}