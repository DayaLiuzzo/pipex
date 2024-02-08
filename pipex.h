/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:43:00 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/08 17:30:43 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include "libft/includes/printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

typedef struct s_rome
{
    char **paths;
    char **command;
    char *commandpath;
    
} t_rome;


int     main(int ac, char   **av, char **env);
char    **get_command(t_rome **rome);
t_rome  *init_struct(void);
void    check_args(int ac, char **av, char **env, t_rome *rome);
int liberation(char *msg, t_rome **rome);
int path_error(char *msg, t_rome **rome);

#endif