# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahir <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 03:03:04 by ozahir            #+#    #+#              #
#    Updated: 2021/11/22 21:35:59 by ozahir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_printf.c	hex_convert.c	nbrlen.c \
	print.c	 un_putnbr.c parsing.c	

OBJ= ${SRC:.c=.o}

CC = gcc
FLAGS= -Wall -Wextra -Werror
HEADER= ft_printf.h
FTLIB= libft/libft.a
NAME= libftprintf.a

all: ${NAME}

${FTLIB}:
	@cd libft; make

${NAME}: ${OBJ} ${HEADER} ${FTLIB} 
	@mv ${FTLIB} ${NAME}
	${CC} -c ${FLAGS} ${SRC}
	@ar -rcs ${NAME} ${OBJ}

clean:
	@rm -f ${OBJ}
	@cd libft; make clean

fclean: clean
	@rm -f ${NAME}

re: fclean all
