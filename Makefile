# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 15:41:57 by dliuzzo           #+#    #+#              #
#    Updated: 2024/02/08 18:21:17 by dliuzzo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAG = -Wall -Wextra -Werror

INC = -I /pipex.h

LIB = -L libft/ -lft

SRCS =	init.c \
		liberation.c \
		command.c \
		main.c \
		utils.c \
		check_args.c \

OBJS = $(SRCS:.c=.o)

NAME = pipex

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft/
	$(CC) $(FLAG) $(OBJS) -o $(NAME) $(INC) $(LIB)

%.o : %.c
	$(CC) $(FLAG) $(INC) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

lclean : 
	make fclean -C libft/

.PHONY: all clean fclean lclean re