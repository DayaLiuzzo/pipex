/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:01:19 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/21 12:03:14 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int ac, char **av, t_rome *rome)
{
	if (ac != 5)
		liberation("des arguments ouuu", rome);
	rome->f1 = open(av[1], O_RDONLY, 0777);
	if (rome->f1 < 0)
		liberation("ERROR", rome);
	rome->f2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (rome->f1 < 0)
		liberation("ERROR", rome);
}
