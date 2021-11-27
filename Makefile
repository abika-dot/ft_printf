# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahir <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 16:45:21 by ozahir            #+#    #+#              #
#    Updated: 2021/11/27 16:03:40 by ozahir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
FLAGS=  -c -Wall -Werror -Wextra
NAME= libftprintf.a
HRADER= ft_printf.h
SRC= numbers.c	parsparam.c \
	ft_printf.c	p_hex.c	\
	strndchar.c
OBJ= ${SRC:.c=.o}

${NAME} : ${OBJ} ${HEADER}
	@${CC} ${FLAGS} ${SRC}
	@ar -rc ${NAME} ${OBJ}

clean:
	rm -rf ${OBJ}

fclean:	clean
	rm -rf ${NAME}

re:	fclean all

all: ${NAME}


