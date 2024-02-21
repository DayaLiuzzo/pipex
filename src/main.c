/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:51:03 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/21 12:07:51 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ft_childlabor(&rome, &fd);
// ft_childlabor(t_rome *rome, int *fd)

int	main(int ac, char **av, char **env)
{
	t_rome	rome;

	init_struct(&rome);
	check_args(ac, av, &rome);
	if (pipe(rome.fd) < 0)
		path_error("Pipe Error", &rome);
	rome.pid1 = fork();
	if (rome.pid1 < 0)
		path_error("Fork Error", &rome);
	if (rome.pid1 == 0)
		ft_childlabor1(&rome, av, env);
	rome.pid2 = fork();
	if (rome.pid2 < 0)
		path_error("Fork Error", &rome);
	if (rome.pid2 == 0)
		ft_childlabor2(&rome, av, env);
	ft_closefd(&rome);
	while (wait(NULL) > 0)
		;
	return (0);
}
