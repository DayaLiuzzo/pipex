# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 15:41:57 by dliuzzo           #+#    #+#              #
#    Updated: 2024/02/16 16:47:29 by dliuzzo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

ifeq ($(MAKECMDGOALS), bonus)
NAME = pipex_bonus
endif

S = src/

ifeq ($(MAKECMDGOALS), bonus)
S = bonus/
endif

I = inc/

L = libft/

O = obj/

D = dep/


CC = cc

CFLAGS = -Wall -Wextra -Werror

ifeq ($(MAKECMDGOALS), debug)
CFLAGS += -g3
#CFLAGS += -fsanitize=address
endif

CFLAGS += -I$I

LDFLAGS = -L$L -lft

SRCS =	$Sinit.c \
		$Sliberation.c \
		$Scommand.c \
		$Smain.c \
		$Sutils.c \
		$Scheck_args.c \
		$Sget_next_line.c \
		$Schild_management.c \
		$Sget_next_line_utils.c
#		$(addprefix $S, examplefolder/)

ifeq ($(MAKECMDGOALS), bonus)
SRCS = $Snomfichier_bonus.c
endif

RM	=	rm -rf

OBJS =	$(SRCS:$S%=$O%.o)

DEP =	$(SRCS:$S%=$D%.d)

all : lib $(NAME)

$O:
	mkdir -p $@

$(OBJS): | $O

$(OBJS): $O%.o: $S%
#	mkdir -p $@
	$(CC) $(CFLAGS) -c $< -o $@

$D:
	mkdir -p $@

$(DEP): | $D

$(DEP): $D%.d: $S%
#	mkdir -p $@
	$(CC) $(CFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<

$(NAME) : $(OBJS) $(DEP)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

lib:
	make -C $L
	
debug: all

cleanobjs:
	$(RM) $(OBJS) $(O)

lclean:
	make fclean -C libft/

cleandep: 
	$(RM) $(DEP) $(D)

clean: cleanobjs cleandep

fclean : clean lclean
	$(RM) $(NAME)
#	$(RM) $(NAME)_bonus

re: fclean all

.PHONY: all clean fclean lclean re debug lib