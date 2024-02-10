/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:43:00 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/10 13:02:12 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include "libft/includes/printf.h"
#include <stdlib.h>
#include <fcntl.h>
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
    char *sub;
    char *exe;
    int i;
    int j;
    int f;
    int id;
    int f1;
    int f2;
    
    
} t_rome;


int     main(int ac, char   **av, char **env);
void    get_command(t_rome *rome, char *av);
void    init_struct(t_rome *rome);
void    check_args(int ac, char **av, char **env, t_rome *rome);
int liberation(char *msg, t_rome *rome);
int path_error(char *msg, t_rome *rome);
void get_paths(t_rome *rome, char **env);
void get_command_path(t_rome *rome);
int ft_strncmpp(char *s1, char *s2, int n);
void free_path(t_rome *rome);
int exec_command(t_rome *rome,char **env);
int ft_exec(t_rome *rome, char *av, char **env);
#endif