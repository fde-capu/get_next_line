# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/05 08:16:16 by fde-capu          #+#    #+#              #
#    Updated: 2020/02/19 00:35:40 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUFFER	=	3

FLAGS	=	-Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER)

SRCS	=	get_next_line.c	\
			get_next_line_utils.c

LIB		=	get_next_line.h

GCC		=	gcc $(FLAGS) $(SRCS)
GCCO	=	gcc -g $(FLAGS) $(SRCS)

EXEF	=	a.out

MAIN	=	main.c

all:

allt:		all zzz
			$(GCCO) $(MAIN)
clean:
			echo 'No objects to clean'

fclean:		clean
			rm -f $(EXEF)

re:			fclean all

t:			allt
			./$(EXEF)

rt:			fclean t

ft:			norm rt

norm:
			norminette -R CheckForbiddenSourceHeader $(SRCS) $(LIB)

fval:		
			valgrind --leak-check=full --show-leak-kinds=all ./a.out

val:		
			valgrind ./a.out

ok:			all
			sed '/\/\//d' get_next_line.c > ok/get_next_line.c
			sed '/\/\//d' get_next_line_utils.c > ok/get_next_line_utils.c
			sed '/\/\//d' get_next_line.h > ok/get_next_line.h
			norminette -R CheckForbiddenSourceHeader ok/get_next_line.c
			norminette -R CheckForbiddenSourceHeader ok/get_next_line.h
			norminette -R CheckForbiddenSourceHeader ok/get_next_line_utils.c

zzz:
			cp get_next_line* ~/_avail/get_next_line/zzz
