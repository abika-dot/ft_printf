# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahir <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 03:03:04 by ozahir            #+#    #+#              #
#    Updated: 2021/11/22 04:39:44 by ozahir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c	hex_convert.c	nbrlen.c \
	print.c	parsing.c

OBJ= ${SRC:.c=.o}

CC = gcc
FLAGS= -Wall -Wextra -Werror
HEADER= ft_printf.h
FTHEADER= libft/libft.h
NAME= libftprintf.a

all: ${NAME}


${NAME}: ${OBJ} ${HEADER} ${FTHEADER}
	${CC} -c ${FLAGS} ${SRC}
	ar -rcs ${NAME} ${OBJ}

clean:
	@rm -f ${OBJ}

fclean: clean
	@rm -f ${NAME}

re: fclean all
