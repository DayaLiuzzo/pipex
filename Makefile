# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 15:41:57 by dliuzzo           #+#    #+#              #
#    Updated: 2024/02/10 15:29:42 by dliuzzo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAG = -Wall -Wextra -Werror -g

INC = -I /pipex.h

LIB = -L libft/ -lft

SRCS =	init.c \
		liberation.c \
		command.c \
		main.c \
		utils.c \
		check_args.c \
		get_next_line.c \
		get_next_line_utils.c \

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