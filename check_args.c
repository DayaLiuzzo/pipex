/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:01:19 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/12 12:46:24 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int ac, char **av, char **env, t_rome *rome)
{
	if (ac <= 4)
		liberation("des arguments ouuu", rome);
	if (!env[0])
		liberation("ou est l environnement mv ?", rome);
	if (ft_strncmpp(av[1], "here_doc", 9))
	{
		rome->id = 3;
		rome->f2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	}
	if (rome->id == 2)
	{
		rome->f1 = open(av[1], O_RDONLY, 0777);
		rome->f2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	}
}
